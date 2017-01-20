def PyLocateValue(magic_number, spread, precision):
    guess = spread / 2
    while abs(guess - magic_number) > precision:
        if guess > magic_number:
            guess = guess - (spread - guess) / 2
        else:
            guess = guess + (spread - guess) / 2
    return guess
