# Hollow Vessels

***Video Game Project***

## Overview

This repository contains the source code and assets for "Hollow Vessels," an SDL 1.2 video game project. This README provides an overview of the project structure and instructions for setting up and running the game.

## Used tech

![Discord](https://img.shields.io/badge/Discord-%235865F2.svg?style=for-the-badge&logo=discord&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white)
![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
![SDL1.2](https://img.shields.io/badge/SDL1.2-%2307405e.svg?style=for-the-badge&logo=sqlite&logoColor=white)

## Project Structure

```sh
.Hollow Vessels
├── bin
│   ├── debug
│   │   └── app
│   ├── obj
│   │   └── main.o
│   ├── release
│   │   └── release.exe
│   └── test
│       └── test.exe
├── conf
│   └── github
├── doc
│   ├── img
│   │   ├── Screenshot 2024-01-31 161342.png
│   │   └── Screenshot 2024-02-05 024135.png
│   ├── Meet 02-07-24
│   │   ├── name of game.txt
│   │   ├── Screenshot 2024-02-07 150026.png
│   │   └── Tuto Map.jpg
│   ├── notes.txt
│   ├── pdf
│   │   └── NONE.pdf
│   ├── rapports
│   │   └── memoleak.txt
│   ├── TODO.txt
│   └── vid
│       └── 20240430_033506.mp4
├── kayori.code-workspace
├── Level1 collisions
├── Level2 collisions
├── LICENSE
├── Makefile
├── pkg
│   ├── font
│   │   └── Groundation Foundation.ttf
│   ├── install_C_Package.cmd
│   ├── install_C_Package.sh
│   └── Testlevel
│       ├── 1 hit.png
│       ├── 2 hit.png
│       ├── 3 hit.png
│       ├── 4 hit.png
│       ├── 5 hit.png
│       ├── Chargement.png
│       ├── FH.png
│       ├── Kayori head MM Left .png
│       ├── Kayori head MM Right .png
│       ├── LEVEL1.png
│       ├── Level 2 no shoot.png
│       ├── Level 2 shoot1.png
│       ├── Level 2 shoot2.png
│       ├── Maptest.png
│       ├── Mini map level1.png
│       ├── Mini map level2.png
│       ├── Mini map PI.png
│       ├── Mini map tuto.png
│       └── Tuto.png
├── project
│   ├── arduino
│   │   ├── build
│   │   │   ├── build.options.json
│   │   │   ├── compile_commands.json
│   │   │   └── sketch
│   │   │       └── sketch_may2a.ino.cpp
│   │   ├── controller
│   │   │   └── controller.ino
│   │   └── obj
│   │       └── controller.obj
│   ├── doc
│   │   ├── collision
│   │   ├── enigma
│   │   ├── enigma_ref
│   │   ├── load_lvl
│   │   ├── ref_SDLKey
│   │   ├── Scores
│   │   ├── settings
│   │   ├── settings_ref
│   │   └── start_menu_ref
│   ├── inc
│   │   ├── Background.h
│   │   ├── Background_Struct.h
│   │   ├── Best_Score.h
│   │   ├── Collisions.h
│   │   ├── Collisions_Struct.h
│   │   ├── enigma.h
│   │   ├── Game.h
│   │   ├── inc.h
│   │   ├── Main_Menu.h
│   │   ├── Mechanics.h
│   │   ├── Mini_Map.h
│   │   ├── Mini_Map_Struct.h
│   │   ├── Multiplayer.h
│   │   ├── Multiplayer_Skins.h
│   │   ├── Pause.h
│   │   ├── Pause_Struct.h
│   │   ├── Quit_Verification.h
│   │   ├── SDL_Msg.h
│   │   ├── serie.h
│   │   ├── settings.h
│   │   ├── speedRun.h
│   │   ├── Start_Menu.h
│   │   ├── Struct_Player.h
│   │   ├── Structure_MP.h
│   │   ├── Structure_MP_Skins.h
│   │   ├── Structures_BS.h
│   │   ├── Structures_MM.h
│   │   ├── Structures_QV.h
│   │   └── tic_tac_toe.h
│   ├── res
│   │   ├── font
│   │   │   ├── Code 7x5.ttf
│   │   │   └── Groundation Foundation.ttf
│   │   ├── img_enigma
│   │   │   ├── img0.png
│   │   │   ├── img1.png
│   │   │   ├── img2.png
│   │   │   ├── img3.png
│   │   │   ├── img4.png
│   │   │   ├── img5.png
│   │   │   └── timer_bar
│   │   │       ├── img10.png
│   │   │       ├── img11.png
│   │   │       ├── img12.png
│   │   │       ├── img13.png
│   │   │       ├── img14.png
│   │   │       ├── img15.png
│   │   │       ├── img16.png
│   │   │       ├── img17.png
│   │   │       ├── img18.png
│   │   │       ├── img19.png
│   │   │       ├── img20.png
│   │   │       ├── img21.png
│   │   │       ├── img22.png
│   │   │       ├── img23.png
│   │   │       ├── img24.png
│   │   │       ├── img25.png
│   │   │       ├── img6.png
│   │   │       ├── img7.png
│   │   │       ├── img8.png
│   │   │       └── img9.png
│   │   ├── img_main_menu
│   │   │   ├── Animation1.png
│   │   │   ├── Animation2.png
│   │   │   ├── MainMenuMulti.png
│   │   │   ├── MainMenu.png
│   │   │   ├── MainMenuQuit.png
│   │   │   ├── MainMenuSettings.png
│   │   │   └── MainMenuStart.png
│   │   ├── img_multiplayer
│   │   │   ├── multiplayer best score.png
│   │   │   ├── multiplayer return.png
│   │   │   └── multiplayer start.png
│   │   ├── img_Multiplayer_Skins
│   │   │   ├── Left arrow.png
│   │   │   ├── Multiplayer skins.png
│   │   │   ├── Play.png
│   │   │   ├── Return arrow.png
│   │   │   ├── Right arrow.png
│   │   │   ├── Skin1.png
│   │   │   ├── Skin2.png
│   │   │   ├── Skin3.png
│   │   │   └── Skin4.png
│   │   ├── img_quit_verification
│   │   │   ├── Quit verification no S.png
│   │   │   └── Quit verification yes S.png
│   │   ├── img_score
│   │   │   └── best scores menu copie.png
│   │   ├── img_settings
│   │   │   ├── img61.png
│   │   │   ├── img62.png
│   │   │   ├── LS
│   │   │   │   ├── img0.png
│   │   │   │   ├── img10.png
│   │   │   │   ├── img11.png
│   │   │   │   ├── img1.png
│   │   │   │   ├── img2.png
│   │   │   │   ├── img3.png
│   │   │   │   ├── img4.png
│   │   │   │   ├── img5.png
│   │   │   │   ├── img6.png
│   │   │   │   ├── img7.png
│   │   │   │   ├── img8.png
│   │   │   │   └── img9.png
│   │   │   └── RS
│   │   │       ├── audio_menu
│   │   │       │   ├── img43.png
│   │   │       │   ├── img44.png
│   │   │       │   ├── img45.png
│   │   │       │   ├── img46.png
│   │   │       │   ├── img47.png
│   │   │       │   ├── img48.png
│   │   │       │   ├── img49.png
│   │   │       │   └── img50.png
│   │   │       ├── controls_menu
│   │   │       │   ├── img_controller
│   │   │       │   │   └── img60.png
│   │   │       │   └── img_keyboard
│   │   │       │       ├── img12.png
│   │   │       │       ├── img13.png
│   │   │       │       ├── img14.png
│   │   │       │       ├── img15.png
│   │   │       │       ├── img16.png
│   │   │       │       ├── img17.png
│   │   │       │       ├── img18.png
│   │   │       │       ├── img19.png
│   │   │       │       ├── img20.png
│   │   │       │       ├── img21.png
│   │   │       │       ├── img22.png
│   │   │       │       ├── img23.png
│   │   │       │       ├── img24.png
│   │   │       │       ├── img25.png
│   │   │       │       ├── img26.png
│   │   │       │       ├── img27.png
│   │   │       │       ├── img28.png
│   │   │       │       ├── img29.png
│   │   │       │       ├── img30.png
│   │   │       │       ├── img31.png
│   │   │       │       ├── img32.png
│   │   │       │       └── img33.png
│   │   │       ├── gamePlay_menu
│   │   │       │   ├── img56.png
│   │   │       │   ├── img57.png
│   │   │       │   ├── img58.png
│   │   │       │   └── img59.png
│   │   │       ├── language_menu
│   │   │       │   ├── img51.png
│   │   │       │   ├── img52.png
│   │   │       │   ├── img53.png
│   │   │       │   ├── img54.png
│   │   │       │   └── img55.png
│   │   │       └── video_menu
│   │   │           ├── img34.png
│   │   │           ├── img35.png
│   │   │           ├── img36.png
│   │   │           ├── img37.png
│   │   │           ├── img38.png
│   │   │           ├── img39.png
│   │   │           ├── img40.png
│   │   │           ├── img41.png
│   │   │           └── img42.png
│   │   ├── img_start_menu
│   │   │   ├── img0.png
│   │   │   ├── img10.png
│   │   │   ├── img1.png
│   │   │   ├── img2.png
│   │   │   ├── img3.png
│   │   │   ├── img4.png
│   │   │   ├── img5.png
│   │   │   ├── img6.png
│   │   │   ├── img7.png
│   │   │   ├── img8.png
│   │   │   └── img9.png
│   │   ├── img_ttt
│   │   │   ├── img0.png
│   │   │   ├── img10.png
│   │   │   ├── img11.png
│   │   │   ├── img12.png
│   │   │   ├── img13.png
│   │   │   ├── img14.png
│   │   │   ├── img1.png
│   │   │   ├── img2.png
│   │   │   ├── img3.png
│   │   │   ├── img4.png
│   │   │   ├── img5.png
│   │   │   ├── img6.png
│   │   │   ├── img7.png
│   │   │   ├── img8.png
│   │   │   └── img9.png
│   │   ├── music
│   │   │   ├── PS2_ Red Screen of Death.mp3
│   │   │   ├── rac_menu_beep.mp3
│   │   │   └── rac_menu_beep.wav
│   │   ├── Pause game
│   │   │   ├── Pause MainMenu.png
│   │   │   └── Pause Resume.png
│   │   ├── PNG frames
│   │   │   └── Default Skin
│   │   │       ├── Dash
│   │   │       │   ├── 10.png
│   │   │       │   ├── 1.png
│   │   │       │   ├── 2.png
│   │   │       │   ├── 3.png
│   │   │       │   ├── 4.png
│   │   │       │   ├── 5.png
│   │   │       │   ├── 6.png
│   │   │       │   ├── 7.png
│   │   │       │   ├── 8.png
│   │   │       │   └── 9.png
│   │   │       ├── Default frames
│   │   │       │   ├── 1.png
│   │   │       │   └── 2.png
│   │   │       ├── Jump
│   │   │       │   ├── Left frames
│   │   │       │   │   └── 3.png
│   │   │       │   └── Right frames
│   │   │       │       └── 3.png
│   │   │       ├── Run frames
│   │   │       │   ├── Left run
│   │   │       │   │   ├── 1.png
│   │   │       │   │   ├── 2.png
│   │   │       │   │   ├── 3.png
│   │   │       │   │   ├── 4.png
│   │   │       │   │   ├── 5.png
│   │   │       │   │   ├── 6.png
│   │   │       │   │   ├── 7.png
│   │   │       │   │   └── 8.png
│   │   │       │   └── Right run
│   │   │       │       ├── 1.png
│   │   │       │       ├── 2.png
│   │   │       │       ├── 3.png
│   │   │       │       ├── 4.png
│   │   │       │       ├── 5.png
│   │   │       │       ├── 6.png
│   │   │       │       ├── 7.png
│   │   │       │       └── 8.png
│   │   │       └── Wall friction
│   │   │           ├── 1.png
│   │   │           └── 2.png
│   │   └── test.jpg
│   └── src
│       ├── Background.c
│       ├── Best_Score.c
│       ├── Collisions.c
│       ├── enigma.c
│       ├── Game.c
│       ├── lib.c
│       ├── main.c
│       ├── Main_Menu.c
│       ├── Mechanics.c
│       ├── MiniMap.c
│       ├── Multiplayer.c
│       ├── Multiplayer_Skins.c
│       ├── Pause.c
│       ├── Quit_Verification.c
│       ├── serie.c
│       ├── settings.c
│       ├── speedRun.c
│       ├── Start_Menu.c
│       └── tic_tac_toe.c
├── README.md
├── Rect_Position
└── Tuto collisions

60 directories, 284 files
```

## How to Use

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/ZouariOmar/Kayori.git
