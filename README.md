ESPectro32 with NB-IoT Backpack
===============================

### What does it do?

Trying to connect to XL Axiata's NB-IoT network with ESPectro32 and NB-IoT backpack. Then it's up to you, it grants you AT command access to SARA R410M 02B module on the backpack.

## Try it yourself

Clone this repository using `--recursive` flag.

```bash
git clone --recursive https://github.com/alwint3r/try-espectro-nbiot-backpack"
```

Compile and upload the code to the ESPectro32 board.

```bash
pio run -t upload
```

Open serial monitor

```
pio device monitor -b 115200
```