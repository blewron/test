def pyramid(rows):
    for i in range(rows):
        # Print asterisks
        print('*' * (i + 1))


def reverse_pyramid(rows):
    for i in range(rows, 0, -1):
        # Print asterisks
        print('*' * i)


# Number of rows for the pyramid
rows = int(input("Enter the number of rows for the pyramid: "))
pyramid(rows)
reverse_pyramid(rows)  # Fixed typo: 'row' -> 'rows'  