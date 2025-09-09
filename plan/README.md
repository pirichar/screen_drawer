# README.md

## Project Name: ScreenDraw

### 1. Project Goal

Create a simple, cross-platform desktop application that acts as a screen overlay, allowing a user to draw and write text directly on their screen. This tool is intended for use during presentations, screen sharing sessions (on Teams, Meet, Slack, etc.), and remote teaching. The application should be written in **C++** and work on both **macOS** and **Windows**.

### 2. Core Features

The application should launch directly into an active drawing mode. All controls and tools will be accessible via a small, floating toolbar.

#### 2.1. The Floating Toolbar

* **Behavior:** A small, movable window that always stays on top of all other applications. This is the main control center.
* **Controls:** The toolbar must contain clear UI elements (e.g., icons, buttons, sliders) for the following tools and actions.

#### 2.2. Drawing & Annotation Tools

1.  **Pen Tool:**
    * Allows for free-hand drawing on the screen.
    * **Customization Controls on Toolbar:**
        * **Color:** A color picker to select the pen color.
        * **Thickness:** A slider or numerical input to control the line width.
        * **Opacity:** A slider or numerical input (0-100%) to control the transparency of the line.

2.  **Text Tool:**
    * When selected, clicking on the screen should create a text input box.
    * The user can type text directly into this box.
    * **Customization Controls on Toolbar:**
        * **Color:** A color picker to select the font color.
        * **Font Size:** A numerical input or dropdown to set the font size.

3.  **Eraser Tool:**
    * Allows the user to erase parts of any existing drawings or text by clicking and dragging over them.

#### 2.3. Global Actions

The toolbar must also contain buttons for these essential actions:

1.  **Undo Last Action:**
    * A button that reverts the very last action taken (e.g., removes the last drawn stroke or the last text box created).

2.  **Clear Screen:**
    * A button that instantly removes all drawings and text from the screen, providing a clean slate.

### 3. Technical Specifications

* **Language:** `C++` (using a modern standard like C++17).
* **Framework:** Use the **Qt Framework (Version 6 or later)**. Qt is ideal for this project because of its excellent cross-platform support for Windows and macOS, powerful graphics capabilities, and robust widget library for creating the UI.
* **Build System:** Use `CMake` to manage the project build process, ensuring it can be easily compiled on both target platforms.

### 4. Implementation Guidance

* **Main Drawing Canvas:** The core of the application should be a fullscreen, borderless, and transparent window that sits on top of all other windows.
    * In Qt, this can be achieved by setting window flags like `Qt::FramelessWindowHint`, `Qt::WindowStaysOnTopHint`, and the attribute `Qt::WA_TranslucentBackground`.
* **Toolbar:** The floating toolbar should be a separate, smaller, non-transparent window, also configured with the `Qt::WindowStaysOnTopHint` flag so it is never obscured.
* **Event Handling:** The application must capture mouse events (press, move, release) on the transparent fullscreen window to handle drawing and erasing.
* **State Management:** The application needs a simple state machine to manage which tool (Pen, Text, Eraser) is currently active. The UI on the toolbar should clearly indicate the selected tool.
* **Undo Stack:** Implement the "Undo" functionality by maintaining a list or stack of drawing actions. Each new drawing/text action is pushed onto the stack, and "Undo" pops the last one off and redraws the scene.