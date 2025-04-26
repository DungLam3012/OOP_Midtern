#include <pybind11/pybind11.h>
#include "zoo.h"
#include "animal.h"
#include "cage.h"

namespace py = pybind11;

PYBIND11_MODULE(libzoo, m) {
    py::class_<Animal>(m, "Animal")
        .def(py::init<const std::string&, const std::string&, const std::string&, int, int>())
        .def("getId", &Animal::getId)
        .def("getName", &Animal::getName)
        .def("getGender", &Animal::getGender)
        .def("getBirthYear", &Animal::getBirthYear)
        .def("getAge", &Animal::getAge)
        .def("setID", &Animal::setID)
        .def("setName", &Animal::setName)
        .def("setGender", &Animal::setGender)
        .def("setBirthYear", &Animal::setBirthYear)
        .def("setAge", &Animal::setAge)
        .def("printInfo", &Animal::printInfo);

    py::class_<Cage>(m, "Cage")
        .def(py::init<const std::string&, int>())
        .def("getCageId", &Cage::getCageId)
        .def("isFull", &Cage::isFull)
        .def("addAnimal", &Cage::addAnimal)
        .def("printAnimals", &Cage::printAnimals);

    py::class_<Zoo>(m, "Zoo")
        .def(py::init<>())
        .def("addAnimal", &Zoo::addAnimal)
        .def("printAllAnimal", &Zoo::printAllAnimal)
        .def("findAnimalById", &Zoo::findAnimalById)
        .def("addCage", &Zoo::addCage)
        .def("findCageById", &Zoo::findCageById)
        .def("addAnimalToCage", &Zoo::addAnimalToCage);
}
