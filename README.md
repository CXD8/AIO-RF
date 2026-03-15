# RF Multifunction Device

An all-in-one RF platform built around the **ESP32-WROOM-32U**, combining Wi-Fi, Bluetooth, and sub-GHz RF into a single battery-powered device with a 2.8" LCD display and USB Type-C charging.

## Disclaimer
**This project is intended for educational and research purposes only**
**The author accepts no liability for regulatory non-compliance resulting from use of this project**
**Users are solely responsible for ensuring compliance with all applicable local laws and regulations**
This project is provided **as-is, with absolutely no warranty of any kind**, express or implied. The author(s) accept **zero responsibility or liability** for any outcome resulting from the use, assembly, or operation of this hardware - including but not limited to property damage, fire, personal injury, or death.

**Use entirely at your own risk. The author(s) have no responsibility whatsoever for anything that goes wrong.**
- **Regulatory Disclaimer**
This project may use uncertified radio frequency (RF) modules. These components have not been independently tested or certified for compliance such as for FCC (USA), CE (EU), or any other regulatory framework.
ard.** This device may use a Protected LiPo/Li-ion battery with a BMS. LiPo/Li-ion batteries can swell, leak, catch fire, or explode if incorrectly charged, stored, handled, or if the hardware malfunctions. The author(s) accept no responsibility for any damage, injury, or death caused by battery failure or misuse.
- **RF transmission.** This device transmits RF signals. It is your sole responsibility to comply with all applicable local, national, and international radio frequency regulations (e.g. FCC, CE, OFCOM). Only operate in a controlled environment where RF emissions can be properly managed.
- **No certification.** This design has not been tested, certified, or approved for any commercial, consumer, safety-critical, or regulatory-controlled application.
- **No guarantees.** The author(s) make no guarantees regarding the accuracy or fitness for purpose of the schematic, BOM, firmware, or any associated documentation.

**By using, building, or operating this project in any form, you accept full and sole responsibility for all risks and any consequences that arise.**

By using this project in any form, you agree to assume all associated risks and responsibilities.

## How to Use
Connect via USB Type-C to flash firmware through the onboard FT232RL. Use the ESP32 to drive the LCD, LEDs, and buttons. The MCP73871 handles LiPo charging automatically when USB is connected.
The charging IC does not have low voltage cut-off. You must use an appropriate protected battery with a BMS. A battery is not required. 

## Why
RF development usually requires juggling multiple separate modules and boards. This consolidates everything into one clean, portable device for wireless experimentation and IoT development.

---
<img width="1470" height="1398" alt="AIO-RF_transparent" src="https://github.com/user-attachments/assets/72ac0143-e6b9-48be-b1f1-1b1b91233d86" />
## Bill of Materials

| # | References | Part | Package | Qty | LCSC |
|---|-----------|------|---------|-----|------|
| 1 | C8, C9, C11, C19, C20, C21, C22 | CL10A226MP8NUNE | C0603 | 7 | [Link](https://www.lcsc.com/product-detail/C86295.html) |
| 2 | C1, C3, C6, C7, C17 | CL10B104KB8NNNC | C0603 | 5 | [Link](https://www.lcsc.com/product-detail/C1591.html) |
| 3 | C12, C13, C18 | CL10A475KO8NNNC | C0603 | 3 | [Link](https://www.lcsc.com/product-detail/C19666.html) |
| 4 | C4, C15 | CL21A106KAYNNNE | C0805 | 2 | [Link](https://www.lcsc.com/product-detail/C15850.html) |
| 5 | C5, C23 | CL10A106KP8NNNC | C0603 | 2 | [Link](https://www.lcsc.com/product-detail/C19702.html) |
| 6 | C14, C16 | OCR101M0JBK-0605 | CAP-TH_BD6.3-P2.50-D1.0-FD | 2 | [Link](https://www.lcsc.com/product-image/C134847.html) |
| 7 | C2 | SPZ1AM471E08000R | CAP-TH_BD6.3-P2.50-D1.0-FD | 1 | [Link](https://www.lcsc.com/product-detail/C122242.html) |
| 8 | R3, R10, R11, R13 | 0603WAF1002T5E | R0603 | 4 | [Link](https://www.lcsc.com/product-detail/C25804.html) |
| 9 | R5, R6, R7 | QR0603F470RP05 | R0603 | 3 | [Link](https://www.lcsc.com/product-detail/C176130.html) |
| 10 | R2, R8 | RC0603FR-0710KL | R0603 | 2 | [Link](https://www.lcsc.com/product-detail/C98220.html) |
| 11 | R9, R12 | 0603WAF5101T5E | R0603 | 2 | [Link](https://www.lcsc.com/product-detail/C23186.html) |
| 12 | R1 | 0603WAF2001T5E | R0603 | 1 | [Link](https://www.lcsc.com/product-detail/C22975.html) |
| 13 | D1 | SMAJ5.0A-C83329 | SMA_L4.3-W2.6-LS5.2-RD | 1 | [Link](https://www.lcsc.com/product-detail/C83329.html) |
| 14 | U1, U9 | AP2114H-3.3TRG1 | SOT-223_L6.7-W3.5-P2.30-BR | 2 | [Link](https://www.lcsc.com/product-image/C150716.html) |
| 15 | U6, U7 | E01-ML01SP4 | WIRELM-TH_E01-ML01SP4 | 2 | [Link](https://www.lcsc.com/product-detail/C97340.html) |
| 16 | U2 | ESP32-WROOM-32U(E) | ESP32-WROOM-32U | 1 | [Link](https://www.lcsc.com/product-detail/C701346.html) |
| 17 | U3 | FT232RL | SSOP-28_5.3x10.2mm_P0.65mm | 1 | [Link](https://www.lcsc.com/product-detail/C8690.html) |
| 18 | U5 | E07-400M10S | COMM-SMD_E07-400M10S | 1 | [Link](https://www.lcsc.com/product-detail/C2965513.html) |
| 19 | U8 | MCP73871-2CCI/ML | QFN-20_L4.0-W4.0-P0.50-BL-EP2.7 | 1 | [Link](https://www.lcsc.com/product-detail/C5121473.html) |
| 20 | SW2, SW3 | TS-1088-AR02016 | SW-SMD_L3.9-W3.0-P4.45 | 2 | [Link](https://www.lcsc.com/product-detail/C720477.html) |
| 21 | LED1, LED2, LED3 | HL-PST-1608H233W(9000-16000K) | LED0603-RD | 3 | [Link](https://www.lcsc.com/product-detail/C219226.html) |
| 22 | BT1 | Battery_Cell | JST_XH_B2B-XH-AM_1x02_P2.50mm_Vertical | 1 | [Link](https://www.lcsc.com/product-detail/C158014.html) |
| 23 | H1 | PZ254R-11-05P | HDR-TH_5P-P2.54-H-M-W10.4 | 1 | [Link](https://www.lcsc.com/product-detail/C492413.html) |
| 24 | LCD1 | HS280S010B | LCD-TH_HS280S010B | 1 | [Link]([https://www.lcsc.com/product-detail/C492413.html](https://www.aliexpress.com/item/32795636902.html)) |
| 25 | USB1 | TYPE-C 16P QTWT | USB-TYPE-C-SMD_TYPE-C-16P-QTWT | 1 | [Link](https://www.lcsc.com/product-detail/C5187472.html) |


## Changelog - Images/3D models may not be up to date
- **08/03/2026** - Sample firmware released
- **08/03/2026** - Traces ran over/under NPTH. This is fixed
