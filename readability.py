# Sources that helped me out:

# https://stackoverflow.com/questions/54134072/how-to-re-prompt-a-user-after-an-invalid-input

# https://www.geeksforgeeks.org/floor-ceil-function-python/

# https://www.geeksforgeeks.org/how-to-convert-float-to-int-in-python/

# https://stackoverflow.com/questions/1155617/count-the-number-of-occurrences-of-a-character-in-a-string

# https://stackoverflow.com/questions/24878174/how-to-count-digits-letters-spaces-for-a-string-in-python

# https://www.geeksforgeeks.org/formatted-string-literals-f-strings-python/


from cs50 import get_string


def main():

    text = get_string("Text: ")

    # calculate average letters and sentences using the functions definfed below

    avg_letters = (100.0000 * ((1.00000 * count_letters(text)) / ((1.00000 * count_words(text)))))
    avg_sentences = (100.0000 * ((1.00000 * count_sentences(text)) / ((1.00000 * count_words(text)))))
    cl_index = round((.0588 * avg_letters) - (.296 * avg_sentences) - 15.8)

    # make necessary conditionals to print
    if cl_index < 1:
        print("Before Grade 1")
    elif cl_index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {cl_index}")


def count_sentences(x):

    #learned this function from 4th link above

    s_count = x.count('.') + x.count('!') + x.count('?')
    return s_count


def count_letters(x):

    # using isalpha function to count number of letters per sentence, adding 1 to a counter for every character that's a letter
    l_count = 0
    for i in range(len(x)):
        if x[i].isalpha():
            l_count = l_count + 1
    return l_count


def count_words(x):

    # same as above, just with isspace(). Using counter starting at 1 because an input like "Hello." needs to register as a sentence
    # despite having no spaces
    w_count = 1
    for i in range(len(x)):
        if x[i].isspace():
            w_count = w_count + 1
    return w_count
    

main()