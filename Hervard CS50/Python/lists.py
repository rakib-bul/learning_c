magician = ["Jami", "Rakib", "Rifat"]

for magic in magician:
    if magic[0] == "R" or magic[2] == None:
        print(f"{magic.title()}! that was a great trick")
    else:
        print("No one found")