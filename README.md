```bash
cd qmk_firmware
git clone https://github.com/Rouji/Ergodone-QMK.git keyboards/ergodone/keymaps/rj
make clean && make ergodone:rj
sudo hid_bootloader_cli -w -v -mmcu=atmega32u4 ergodone_rj.hex
```
