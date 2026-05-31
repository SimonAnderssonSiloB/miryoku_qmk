# Custom QMK Keymaps

Custom Colemak DH layouts with Miryoku-style layers for three keyboards.

## Keyboards

| Keyboard | Keymap | Description |
|----------|--------|-------------|
| crkbd (Corne) | `simoncolemak` | Split 3x6+3, standard layout |
| crkbd (Corne) | `simoncolemak_bastardkb` | Split 3x6+3, for BastardKB Charybdis without trackball |
| bastardkb/charybdis/3x6/v2/splinky_3 | `simoncolemak` | Split 3x6, with trackball (2 right thumbs) |

## Setup

### 1. Install QMK CLI (macOS)

```sh
brew install qmk/qmk/qmk
brew tap osx-cross/avr
brew tap osx-cross/arm
brew install osx-cross/avr/avr-gcc@8
brew install osx-cross/arm/arm-gcc-bin@8
```

Add to `~/.zshrc`:

```sh
export PATH="/opt/homebrew/opt/avr-gcc@8/bin:$PATH"
export PATH="/opt/homebrew/opt/arm-gcc-bin@8/bin:$PATH"
```

### 2. Clone and configure

```sh
git clone git@github.com:SimonAnderssonSiloB/miryoku_qmk.git
cd miryoku_qmk
qmk setup -H .
```

## Build

```sh
# Corne (crkbd)
qmk compile -kb crkbd -km simoncolemak

# BastardKB Charybdis without trackball (uses crkbd layout)
qmk compile -kb crkbd -km simoncolemak_bastardkb

# BastardKB Charybdis with trackball
qmk compile -kb bastardkb/charybdis/3x6/v2/splinky_3 -km simoncolemak
```

## Flash

Put the keyboard into bootloader mode (double-tap reset), then:

```sh
qmk flash -kb crkbd -km simoncolemak
qmk flash -kb crkbd -km simoncolemak_bastardkb
qmk flash -kb bastardkb/charybdis/3x6/v2/splinky_3 -km simoncolemak
```
