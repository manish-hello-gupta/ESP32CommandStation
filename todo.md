# DCC++ESP32 Feature/Bug Tracking list
This document tracks features and bug fixes that are planned.

## v1.3.0
The primary focus for this will be improving the LCC integration and solve the crash caused by the DCC signal generation code.

### Updates from v1.2.1

#### DCC System

- [x] fix signal generation so it doesn't crash up when spi_flash disables cache.

#### LCC Integration

- [ ] Traction proxy impl.
- [ ] Broadcast events for turnout state change.
- [ ] Discard turnout events when turnout already in expected state (drop duplicate events).
- [ ] Integrate the WiFiConfiguration CDI element.

#### Nextion Interface

- [x] fix screen type detection.
- [x] lock to title screen until WiFi connects.

#### Web Interface
- [x] Add space in footer for clock so date/time are not smashed together.

#### Configuration Persistence
- [ ] Split up monolithic json files to instead be individual files in unique directories.
- [ ] consider switch to binary format vs json format to save space on FS

## Future planning:
The entries below are not tracked to a specific release or in any particular priority order.

### DCC System

- [ ] implement RailCom cut-out for OPS track.
- [ ] continue sending eStop packet until eStop is cleared.
- [ ] implement BG task for prog track.

### Config

- [ ] move wifi config to NVS/SPIFFS.
- [ ] dynamic command station config via web
- [ ] SoftAP support for initial config and "non-home" network. (https://github.com/atanisoft/DCCppESP32/issues/4)

### Web Interface

- [ ] auto-refresh of status pages
- [ ] add busy/wait spinner for when data is loading (or being refreshed) in the web interface
- [ ] investigate tcp/ip hang (AsyncTCP LwIP crash? consider replacements for AsyncWebServer?)
- [ ] WiThrottle support (https://github.com/atanisoft/DCCppESP32/issues/15)

### LCC Integration

- [ ] adjust InfoScreen LCC details so they are actually useful, right now it is a placeholder.
- [ ] implement CV memory space.

### Nextion Interface

- [ ] auto turn on of track power from Nextion when interacting with loco/turnouts.
- [ ] add notification of turnout state change when changed external to the nextion code
- [ ] replace Routes page with a Setup page which will include route creation
- [ ] implement automatic resolver for component id during page initialization so we can drop component IDs from the argument list
- [ ] move screen detection code into NeoNextion lib.
- [ ] add support for Nextion Upload via OTA in NeoNextion.

### OTA

- [ ] OTA support via JMRI / LCC
- [ ] return to normal mode on Nextion when OTA fails.
- [ ] OTA SPIFFS update (if needed, unsure as of now)

### InfoScreen

- [ ] move to multi-thread aware Wire library when available

### Documentation
No tasks have been added yet.