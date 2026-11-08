# Contributing to VYTRON

Thank you for your interest in contributing to the VYTRON Smart Viscosity Measurement and Control System!

## 📜 License Notice

This project is **All Rights Reserved**. By contributing, you agree that your contributions are subject to the same license terms as the repository (`LICENSE.txt`). No contribution may be copied, modified, or distributed outside this project without the author's prior written permission.

## 🐛 Reporting Issues

Before opening an issue, please check if it has already been reported. When opening a new issue, include:

- A clear title and description
- Steps to reproduce (if applicable)
- Hardware version (Mega 2560, Nano, JSS-860H, etc.)
- Firmware version / commit hash
- Photos or screenshots (if relevant)
- Expected vs. actual behavior

## 🔧 Pull Requests

1. Fork the repository and create a new branch from `main`.
2. Make your changes in a focused commit.
3. Update documentation (`docs/`) if your change affects usage, wiring, or assembly.
4. Test on the actual hardware if possible.
5. Open a pull request with a clear description of what was changed and why.

## 💻 Coding Standards (Arduino / Embedded)

- Use consistent indentation (2 or 4 spaces).
- Avoid `String` class in performance-critical ISR or loop code to prevent memory fragmentation.
- Keep interrupt service routines (ISR) short; do not call `delay()` or `Serial.print()` inside an ISR.
- Use `volatile` for variables shared between ISR and `loop()`.
- Pin definitions should be at the top of the sketch with `#define`.

## 📖 Documentation

- New features or hardware changes should be accompanied by an update in the relevant `docs/` file.
- Keep Turkish and English UI labels consistent where applicable.

## 📬 Contact

For permission requests or contribution questions, email: **rahimzaderashad1@gmail.com**