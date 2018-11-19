# Daybreak Game Engine

The Daybreak Game Engine is a work-in-progress game engine designed to be easy-to-use and portable across platforms.

Note: This document assumes that the engine has been ported to CMake-deployable build system and the change from OpenGL to Vulkan has been implemented.

## Getting Started

Download or clone the repo to a working directory.

### Prerequisites

The Vulkan SDK is required to build the engine. The Vulkan SDK can be downloaded/installed from: 

```
https://vulkan.lunarg.com/sdk/home
```

### Installing

After downloading or cloning the repo and installing the Vulkan SDK

1. Run CMake

```
cmake
```

## Built With

* [GLFW](https://www.glfw.org/) - Window-creation API
* [Vulkan](https://www.khronos.org/vulkan/) - Graphics API
* [tinyobjloader](https://github.com/syoyo/tinyobjloader) - For mesh/model loading
* [FreeImage](https://freeimage.sourceforge.net) - For image loading

## Contributing

If you're interested in contributing, feel free to create your own pull requests or contact me with any questions at ctc7359@rit.edu. I would appreciate that you contact me if you wish to fork this repo.

## Versioning

Versioning will commence once a stable first build is released.

## Authors

* **Carson Clarke-Magrab** - *Initial work* - [carsonclarke570](https://github.com/carsonclarke570)

## License

This project is licensed under the Apache 2.0 License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* My friends, for not being in any way involved with this project

