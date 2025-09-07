

class Player:
    def __init__(self, name=""):
        self.player_name = name

def main():
    print("RPG Character Creator")
    name = input("Enter Player Name >> ")

    # Create a Player instance with the inputted name
    player1 = Player(name)

    print("Player name is:", player1.player_name)


## Run Program
if __name__ == "__main__":
    main()
