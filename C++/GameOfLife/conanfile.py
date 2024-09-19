from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeDeps


class ConanDependencies(ConanFile):
    
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    
    def requirements(self):
        self.requires("glfw/3.3.4")
        self.requires("glew/2.1.0")
        self.requires("opengl/system")
        self.requires("nlohmann_json/3.10.5")