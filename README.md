# Patchwork Scientific Figures

**Patchwork Scientific Figures** is a cross-platform graphical application (developed in C++ with Qt) designed for creating high-quality, publication-ready scientific figures.  

Unlike general-purpose tools (PowerPoint, LibreOffice Impress) or programming-based workflows (R, Python), this application focuses on **reproducibility, visual consistency, optimal layout, and long-term project archiving**.  
It is especially useful in biology and related research fields, researchers are not programers and where figure preparation often relies on non-specialized software. Packages such as R cowplot or Python matplotlib packages are gold Standard for datascientist and bioinformaticians but no real UI alternative exist for clinicians and biologists.

---

## Features

- Import multiple images from a folder (JPEG, PNG).  
- Automaticaly add pictures to a grid.
- Add titles and subtiles for the entire figure.  
- Reposition images easily with drag-and-drop.  
- Export the final layout to PNG or PDF.  
- Save and reload projects for future editing (non-destructive workflow).  

---

## Installation

### Required packages

- `qttools5-dev`  
- `qttools5-dev-tools`  
- `g++` (or another C++ compiler)  
- `cmake` (recommended for building)  

---

## Usage

1. Launch the application.  
2. Import images from a folder.  
3. Arrange the order of figures with drag-and-drop.  
4. Add title and subtitle
5. Export as PNG or PDF for publication.  
6. Save your project for later modifications.  

---

## Development

- **Language:** C++  
- **Framework:** Qt 5  
- **Build system:** CMake (recommended)  
- **Platform:** Linux (tested), cross-platform (Windows/macOS supported via Qt)  

---

## License

[GNU General Public License](LICENSE) – free to use, modify, and distribute.
