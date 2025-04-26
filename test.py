import tkinter as tk
from tkinter import messagebox

class Animal:
    def __init__(self, name, species):
        self.name = name
        self.species = species

    def __str__(self):
        return f"{self.name} ({self.species})"

class ZooApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Zoo Management System")
        self.animals = []

        # Label
        self.label = tk.Label(root, text="Zoo Management System", font=("Helvetica", 16))
        self.label.grid(row=0, column=0, columnspan=2)

        # Input for animal name and species
        self.name_label = tk.Label(root, text="Animal Name:")
        self.name_label.grid(row=1, column=0)
        self.name_entry = tk.Entry(root)
        self.name_entry.grid(row=1, column=1)

        self.species_label = tk.Label(root, text="Animal Species:")
        self.species_label.grid(row=2, column=0)
        self.species_entry = tk.Entry(root)
        self.species_entry.grid(row=2, column=1)

        # Buttons
        self.add_button = tk.Button(root, text="Add Animal", command=self.add_animal)
        self.add_button.grid(row=3, column=0)

        self.show_button = tk.Button(root, text="Show Animals", command=self.show_animals)
        self.show_button.grid(row=3, column=1)

        self.search_button = tk.Button(root, text="Search Animal", command=self.search_animal)
        self.search_button.grid(row=4, column=0)

        self.delete_button = tk.Button(root, text="Delete Animal", command=self.delete_animal)
        self.delete_button.grid(row=4, column=1)

        # Listbox to show animals
        self.animal_listbox = tk.Listbox(root, width=50, height=10)
        self.animal_listbox.grid(row=5, column=0, columnspan=2)

    def add_animal(self):
        name = self.name_entry.get()
        species = self.species_entry.get()

        if not name or not species:
            messagebox.showwarning("Input Error", "Please provide both name and species")
            return

        new_animal = Animal(name, species)
        self.animals.append(new_animal)
        self.name_entry.delete(0, tk.END)
        self.species_entry.delete(0, tk.END)
        messagebox.showinfo("Animal Added", f"{name} has been added to the zoo.")

    def show_animals(self):
        self.animal_listbox.delete(0, tk.END)
        if self.animals:
            for animal in self.animals:
                self.animal_listbox.insert(tk.END, str(animal))
        else:
            self.animal_listbox.insert(tk.END, "No animals in the zoo yet.")

    def search_animal(self):
        search_term = self.name_entry.get().lower()
        self.animal_listbox.delete(0, tk.END)
        found = False

        for animal in self.animals:
            if search_term in animal.name.lower():
                self.animal_listbox.insert(tk.END, str(animal))
                found = True

        if not found:
            self.animal_listbox.insert(tk.END, "No animals found.")

    def delete_animal(self):
        try:
            selected_index = self.animal_listbox.curselection()[0]
            selected_animal = self.animals[selected_index]
            self.animals.remove(selected_animal)
            self.animal_listbox.delete(selected_index)
            messagebox.showinfo("Animal Removed", f"{selected_animal.name} has been removed from the zoo.")
        except IndexError:
            messagebox.showwarning("Selection Error", "Please select an animal to delete.")

# Main
if __name__ == "__main__":
    root = tk.Tk()
    app = ZooApp(root)
    root.mainloop()
