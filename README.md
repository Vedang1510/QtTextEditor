# QtTextEditor

This repository contains a Qt C++ application for a text editor with various formatting features and an "About Me" section.

## How to Run the Code

To run this application, follow these steps:

1. Clone the repository to your local machine:

git clone https://github.com/Vedang1510/QtTextEditor.git


2. Open the project in Qt Creator.

3. Build and run the project.

## What Has Been Done

- Implemented a basic text editor using Qt's QTextEdit widget.
- Added toolbar functionalities for bold/unbold, superscript, and subscript.
- Created an "About Me" dialog displaying a resume.

## Issues/Challenges

- Handling text formatting and alignment can be complex due to QTextEdit's rich text capabilities.
- Ensuring cross-platform compatibility and responsiveness.
- Managing dependencies and version control.

## Features

- **Text Formatting**: Toggle between bold and normal font weight. Apply superscript and subscript styles.
- **About Me**: Display personal information and resume in a dialog box.

Folder Arrangement

Ensure your project files are well-organized within the repository, typically Qt Creator manages this by default:

QtTextEditor/
├── .gitignore
├── QtTextEditor.pro
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
├── mainwindow.ui
└── README.md
