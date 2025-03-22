
def pirate(args):
    print("1")
    print(args)
    def plunder(args):
        return args
    return plunder

if __name__ == "__main__":
    result = pirate(pirate(pirate(None)))(5)
    print(result)
    result = pirate(pirate(pirate))(7)
    print(result)