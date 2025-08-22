<img width="1000" alt="OcuKnow banner" src="https://github.com/user-attachments/assets/f6c3dc91-f785-469f-ad0e-1b19a4b0acf4" />

# OcuKnow

### *OcuKnow* is an interactive educational application built with Qt and C++. It allows medical students to explore a virtual model of the human eye, including a study guide and interactive quiz mode. Designed for clarity and accessibility, OcuKnow is ideal for students studying anatomy or preparing for exams.

---

## Table of Contents

- [Environment](#environment)
- [Installation](#installation)
- [File Descriptions](#file-descriptions)
- [Usage](#usage)
  - [Study Guide](#study-guide)
  - [Quiz Mode](#quiz-mode)
- [Key Features](#key-features)
- [Challenges](#challenges)
- [Authors](#authors)
- [License](#license)

---

## Environment

This project was developed and tested in:

- **Operating System**: Ubuntu 22.04 (also tested in Dockerized environments)
- **Qt Version**: Qt 6.4+
- **C++ Version**: C++17+
- **CMake**: 3.26+
- **IDE**: Visual Studio Code and Qt Creator

---

## Installation

Clone the repository and install dependencies:

```bash
git clone https://github.com/NecroKnightMare/OcuKnow.git
cd OcuKnow/src
mkdir build && cd build
cmake ..
cmake --build .
```

You will also need Qt 6 installed. You can download it via:

[Qt Installer](https://www.qt.io/download-qt-installer)

Optional: Use **Qt Creator** or **VS Code with Qt extensions** for better GUI support.

---

## File Descriptions

- `main.cpp`: Entry point of the application. Handles navigation between splash screen, quiz, and study guide.
- `UI/intro/introwidget.cpp/.h`: Main splash screen with animated background and navigation buttons.
- `UI/quiz/quiz.cpp/.h`: Logic and UI for the quiz feature.
- `UI/credits/creditswidget.cpp/.h`: Displays credits with a return option.
- `UI/eyemodel.ui`: Qt Designer file for the anatomical eye interface.
- `graphics/ocuknow_intro.gif`: Splash animation GIF.
- `graphics/half_image_eye.jpg`: Background image for the study guide.
- `resources.qrc`: Qt resource file linking embedded assets.
- `questions.txt`: Source file for quiz content.

---

## Usage

From the `build` folder, launch the program:

```bash
./OcuKnow
```

Upon launch, you'll see the animated splash screen with three options:

- **Enter Study Guide**
- **Take Quiz**
- **Credits**

---

### Study Guide

The Study Guide is a visual UI created using Qt Designer and provides an interactive model of the eye. Users can explore different anatomical parts of the eye using mouse-over or buttons. A labeled diagram helps users visualize the information.

---

### Quiz Mode

Clicking "Take Quiz" starts a multiple-choice quiz based on `questions.txt`. It includes:

- A splash screen with a Start button
- Multiple-choice questions with navigation
- A score screen and retry option

---

## Key Features

- Animated splash screen using GIFs
- Translucent and styled UI buttons
- Responsive layouts and custom fonts
- Study Guide with anatomical eye model
- Quiz feature with question parsing and scoring
- Themed styling consistent across views

---

<img width="792" height="451" alt="Screenshot 2025-04-21 135342" src="https://github.com/user-attachments/assets/c8f24497-8a67-4f67-8b4c-2e47c95950d6" />

---

## Challenges

Building OcuKnow came with its fair share of hurdles. Getting the interactive diagram of the human
eye to feel both accurate and easy to use was one of the biggest ones — it had to look good, but
also clearly teach something at a glance. Working with Qt meant learning how to juggle layouts,
signals, and event handling so the app responded smoothly when users clicked or hovered over
different parts of the diagram.

Another challenge was keeping the code organized as new pieces like the splash screen, main menu,
and interactive features were added. It was easy for things to get messy, so planning ahead and
keeping the project modular was really important. Performance also came up — making sure the
graphics and overlays ran smoothly on different systems took extra polish. And on top of the
technical side, it was always a balancing act to simplify complex biology into something clear,
engaging, and not overwhelming.

---

## Authors

- **Ariel Lopez**  
  [GitHub](https://github.com/NKN_Neko)  
  [LinkedIn](https://www.linkedin.com/in/arielnkm369)  
  [Email](alexandrea.ariel@gmail.com)

	Ariel Lopez womp womp womp

- **Stephen Newby**  
  [GitHub](https://github.com/TheSnewby/)  
  [LinkedIn](https://www.linkedin.com/in/stephenjnewby/)  
  [Email](stephen.j.newby@gmail.com)

	Stephen Newby blah blah blah

- **Nash Thames**  
  [GitHub](https://github.com/internashionalist)  
  [LinkedIn](https://www.linkedin.com/in/nashthames/)  
  [Email](taylor.thames@atlasschool.com)

	Nash Thames is an aspiring software developer with a strong foundation in computer science,
	including advanced algorithms, systems programming, and Linux environments. 
	He is passionate about problem-solving and dedicated to developing reliable, efficient, and
	well-architected software. He is engaged in continuous learning and is interested in
	contributing to research or projects that explore the intersection of software engineering,
	distributed systems, and emerging technologies.

---

## License

This project is released under the Public Domain - free to use, modify, and distribute.

