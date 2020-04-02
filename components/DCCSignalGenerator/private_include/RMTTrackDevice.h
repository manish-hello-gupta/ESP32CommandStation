/**********************************************************************
ESP32 COMMAND STATION

COPYRIGHT (c) 2019-2020 Mike Dunston

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see http://www.gnu.org/licenses
**********************************************************************/

#ifndef _RMT_TRACK_DEVICE_H_
#define _RMT_TRACK_DEVICE_H_

#include <driver/rmt.h>
#include <driver/uart.h>
#include <soc/uart_reg.h>
#include <soc/uart_struct.h>
#include <esp_vfs.h>

#include <dcc/Packet.hxx>
#include <dcc/PacketFlowInterface.hxx>
#include <dcc/RailCom.hxx>
#include <dcc/RailcomHub.hxx>
#include <freertos_drivers/arduino/DeviceBuffer.hxx>
#include <freertos_drivers/arduino/RailcomDriver.hxx>
#include <os/OS.hxx>
#include <utils/Atomic.hxx>
#include <utils/macros.h>
#include <utils/Singleton.hxx>
#include <utils/StringPrintf.hxx>

#include "can_ioctl.h"
#include "MonitoredHBridge.h"
#include "sdkconfig.h"

class RMTTrackDevice : public dcc::PacketFlowInterface, private Atomic
{
public:
  RMTTrackDevice(openlcb::Node *node, const char *name, const rmt_channel_t channel
               , const uint8_t preambleBitCount, size_t packet_queue_len
               , gpio_num_t pin, RailcomDriver *railcomDriver);

  // VFS interface helper
  ssize_t write(int, const void *, size_t);

  // VFS interface helper
  int ioctl(int, int, va_list);

  // RMT callback for transmit completion. This will be called via the ISR
  // context but not from an IRAM restricted context.
  void rmt_transmit_complete();

  // Used only for DCCProgrammer OPS track requests, TBD if this can be removed.
  void send(Buffer<dcc::Packet> *, unsigned);

  // enables the generation of the DCC signal.
  void enable();

  // disables the generation of the DCC signal.
  void disable();

  // returns true if the DCC signal is active.
  bool is_enabled()
  {
    return active_;
  }

private:
  // maximum number of RMT memory blocks (256 bytes each, 4 bytes per data bit)
  // this will result in a max payload of 192 bits which is larger than any
  // known DCC packet with the addition of up to 50 preamble bits.
  static constexpr uint8_t MAX_RMT_MEMORY_BLOCKS = 3;

  // maximum number of bits that can be transmitted as one packet.
  static constexpr uint8_t MAX_DCC_PACKET_BITS = (RMT_MEM_ITEM_NUM * MAX_RMT_MEMORY_BLOCKS);

  const char *name_;
  const rmt_channel_t channel_;
  const uint8_t preambleBitCount_;
  RailcomDriver *railcomDriver_;
  Atomic packetQueueLock_;
  DeviceBuffer<dcc::Packet> *packetQueue_;
  Notifiable* notifiable_{nullptr};
  int8_t packetRepeatCount_{0};
  bool active_{false};

  DISALLOW_COPY_AND_ASSIGN(RMTTrackDevice);
};

#endif // _RMT_TRACK_DEVICE_H_
