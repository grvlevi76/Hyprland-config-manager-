# Hyprland Config Manager

A simple CLI-based C project to **backup, switch, and reload Hyprland configuration files** with ease — built for Linux power users who frequently tinker with their Hyprland setups.

---

## 🧠 Features

- 🔄 **Backup** current Hyprland config with timestamped filenames
- 🔁 **Switch** between saved config files
- ♻️ **Reload** Hyprland instantly using `hyprctl`
- ❌ Input validation to prevent crashes from invalid input
- 📂 Directory scanning to dynamically list available backups

---

## 🛠️ Technologies Used

- C Programming Language (Standard C Libraries)
- Linux file handling (`FILE`, `DIR`, `readdir`)
- Time manipulation with `time.h`
- System calls (`system("hyprctl reload")`)

---

## 🧰 Project Structure

```bash
Hyprland-config-manager/
├── config.c        # Main CLI logic and menu
├── backup.c        # Handles config backup with timestamping
├── switch.c        # Switches between saved configs
├── config.h        # Function declarations


---

⚙️ How to Use

1. 🔧 Make sure arch linux and  Hyprland is installed and configured.


2. 👇 Run the executable (after compiling):

gcc config.c backup.c switch.c -o hyprmanager
./hyprmanager


3. ☑️ Select an option:

1: Backup current config

2: Switch to an old config

3: Reload Hyprland

4: Exit




⚠️ Backups are saved in:
/home/gaurav/.config/hypr/backup/

Edit paths if you're not "gaurav" 
