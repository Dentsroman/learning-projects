from conan import ConanFile
from conan.tools.cmake import CMakeToolchain


class ConanDependencies(ConanFile):
    
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"
    
    def requirements(self):
        self.requires("glfw/3.3.4")
        self.requires("opengl/system")
        

    def generate(self):
        tc = CMakeToolchain(self)
        tc.user_presets_path = False
        tc.generate()