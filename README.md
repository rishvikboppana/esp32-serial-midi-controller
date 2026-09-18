# esp32-serial-midi-controller

'''
========================================================================================
                      BREADBOARD CIRCUIT SCHEMATIC DIAGRAM
               Project: Custom Low-Latency ESP32 Serial MIDI Controller
========================================================================================

    [ LILYGO T-DISPLAY v1.1 ]                 [ 840-POINT BREADBOARD RAIL SYSTEM ]
    ┌───────────────────────┐                 ┌──────────────────────────────────────┐
    │          3V3 ─────────┼────────────────>│  (+) RED POWER RAIL                  │
    │            G ─────────┼────────────────>│  (-) BLUE GROUND RAIL                │
    │      GPIO 12 ─────────┼─────┐           └──────────────────────────────────────┘
    │      GPIO 13 ─────────┼───┐ │
    └───────────────────────┘   │ │
                                │ │
    [ TACTILE SWITCH 1: NOTE C ]│ │           [ TACTILE SWITCH 2: NOTE D ]
    ┌───────────────────────┐   │ │           ┌───────────────────────┐
    │  [Top-Left Pin]       │<──┼─┘           │  [Top-Left Pin]       │<──┐
    │     │                 │   │             │     │                 │   │
    │     ├──[10kΩ Resistor]┼───┼───┐         │     ├──[10kΩ Resistor]┼───┼───┐
    │                       │   │   │         │                       │   │   │
    │  [Bottom-Right Pin]   │   │   │         │  [Bottom-Right Pin]   │   │   │
    └─────┬─────────────────┘   │   │         └─────┬─────────────────┘   │   │
          │                     │   │               │                     │   │
          ▼                     ▼   ▼               ▼                     ▼   ▼
     (To Red Rail)        (To G12) (To Blue Rail) (To Red Rail)         (To G13) (To Blue Rail)
       [+3.3V]            [Signal]   [GND]          [+3.3V]             [Signal]   [GND]

========================================================================================
                                ELECTRICAL NETLIST LOGIC
========================================================================================
1. POWER BUS LOOP:
   * LilyGO Pin [3V]   ────────> Connects to long Red Outer Strip (+)
   * LilyGO Pin [G]    ────────> Connects to long Blue Outer Strip (-)

2. KEY SWITCH 1 MATRIX (Middle C / MIDI Note 60):
   * Path A (Power input):     Red Rail (+) ───> Jumper Wire ───> Switch 1 [Bottom-Right Pin]
   * Path B (Signal processing): LilyGO [GPIO 12] ───> Jumper Wire ───> Switch 1 [Top-Left Pin]
   * Path C (Static drain):    Switch 1 [Top-Left Pin] ───> 10kΩ Resistor ───> Blue Rail (-) [GND]

3. KEY SWITCH 2 MATRIX (Note D / MIDI Note 62):
   * Path A (Power input):     Red Rail (+) ───> Jumper Wire ───> Switch 2 [Bottom-Right Pin]
   * Path B (Signal processing): LilyGO [GPIO 13] ───> Jumper Wire ───> Switch 2 [Top-Left Pin]
   * Path C (Static drain):    Switch 2 [Top-Left Pin] ───> 10kΩ Resistor ───> Blue Rail (-) [GND]
========================================================================================
'''
