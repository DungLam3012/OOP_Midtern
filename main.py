import libzoo

# Khởi tạo đối tượng Zoo
zoo = libzoo.Zoo()

# Tạo các động vật
animal1 = libzoo.Animal("001", "Lion", "Male", 2015, 6)
animal2 = libzoo.Animal("002", "Tiger", "Female", 2016, 5)

# Thêm động vật vào Zoo
zoo.addAnimal(animal1)
zoo.addAnimal(animal2)

# In thông tin các động vật trong zoo
zoo.printAllAnimal()
