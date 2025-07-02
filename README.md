# 🎮 so_long

## 📜 Description
`so_long` is a simple 2D game built using MiniLibX. The goal of the game is to navigate through a map, collect all collectibles, and reach the exit.

## ✨ Features
- 🎮 Player movement using `WASD`
- 🏆 Collectible items
- 🚪 Exit once all items are collected
- 👾 Basic enemy AI (optional)
- 🖼️ Textured walls and floor using `.xpm` files

## ⚙️ Installation
### 📌 Requirements:
- 🖥️ GCC compiler
- 🛠️ `make`
- 🏗️ MiniLibX (must be installed separately)
- 🖥️ X11 libraries (`libxext-dev` and `libx11-dev` for Linux)

### 📥 Installing MiniLibX
Since `mlx` is not included in this repository, you must install it manually:

#### 🔹 For Linux:
```sh
sudo apt-get install libxext-dev libx11-dev
cd /usr/local
sudo git clone https://github.com/42Paris/minilibx-linux.git mlx
cd mlx
make
```
Then, when compiling, link it with `-L/usr/local/mlx -lmlx -lXext -lX11`.

#### 🔹 For macOS:
```sh
brew install minilibx
```

### 📂 Steps to Compile and Run:
1. 📥 Clone the repository:
   ```sh
   git clone https://github.com/Ali-Fayad/so_long.git
   cd so_long
   ```
2. 🏗️ Compile the project:
   ```sh
   make
   ```
3. 🎮 Run the game:
   ```sh
   ./so_long maps/map.ber
   ```

## 🎮 Controls
- ⬆️⬇️⬅️➡️ `WASD` → Move player
- ❌ `ESC` → Quit game

## 📁 Folder Structure
```
so_long/
│── 📂 Include/         # Header files
│── 📂 Srcs/            # Source files
│── 📂 xpms/            # Textures
│── 📂 mlx/             # Here should be the mlx
│── 📜 Makefile         # Compilation script
│── 📖 README.md        # Project documentation
```

## 📜 License
This project is open-source and available under the MIT License.

