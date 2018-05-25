```bash
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
git clone https://github.com/Rouji/Ergodone-QMK.git keyboards/ergodone/keymaps/rj
#export C_INCLUDE_PATH=/usr/avr/sys-root/include
make clean && make ergodone:rj
sudo hid_bootloader_cli -w -v -mmcu=atmega32u4 ergodone_rj.hex
```
