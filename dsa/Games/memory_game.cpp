/**
 * @file
 
 * @brief A simple [Memory Game](https://en.wikipedia.org/wiki/Matching_game)
 * with "3 different sizes" and multiple letters.
 
 * @details
 * The game consists on finding "the pair" of all the given letters depending
 * on the table size. Once all of the instances are all found, the game will end
 * and will ask you if you'd like to play again or not.
 
 * It provides "3 different sizes" available that the user can choose (4x2,
 * 5x2, 7x2). 7x2 being the biggest table size and hardest mode. The bigger the
 * size, "the more letters are available".
 *
 * @author [David Leal](https://github.com/Panquesito7)
 */

#include <algorithm> // for std::shuffle()
#include <cstdlib> // for std::srand()
#include <ctime> // for std::time()
#include <iostream> // for IO operations()
#include <random> // for std::mt19937
#include <vector> // for std::vector

#ifdef _WIN32
#include <Windows.h> // for Sleep();
template <typename T>
constexpr typename std::enable_if<std::is_integral<T>::value, void>::type SLEEP(
    T milliseconds) {
        Sleep(milliseconds * 1000);
    }
#else
#include <unistd.h> // for sleep();
template <typename T>
constexpr T SLEEP(T seconds) {
    return sleep(seconds);
}
#endif

/**
 * @namespace
 * @brief (Mini)game implementations.
 */
namespace games {
/**
 * @namespace
 * @brief Functions for the [Memory Game] implementation
 */
namespace memory_game {
/**
 * @brief Utility function to verify if the given input is a number or not.
 * This is very useful to prevent the program being stuck in a loop.
 * @tparam T The type of the input
 * @param input The input to check.
 * @returns false if the input IS empty or if it contains a non-digit character
 * @returns true if the input is NOT empty and if it contains only digit
 * characters
 */
template <typename T>
bool is_number(const T &input){
    if (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(256, '\n')

        return false;
    }

    return false;
}
/**
 * @brief Initializes the table with the letters.
 * @tparam T The type of the table.
 * @param table The table to initialize.
 * @returns void
 */
template <typename T>
void init(std::vector<T> *table){
    std::vector<char> letters(7);

    // Decrease / increase the number of letters depending on the size.
    if((*table).size() == 10) // 5 x 2
        letters = {'A', 'E', 'Z', 'P', 'D'};
    else if ((*table).size() == 8)  // 4 x 2
        letters = {'A', 'E', 'Z', 'D'};
    else if ((*table).size() == 14) // 7 x 2
        letters = {'A', 'E', 'Z', 'P', 'D', 'B', 'M'};

    std::vector<char> pairs;
    for(char letter : letters) {
        pairs.push_back(letter);
        pairs.push_back(letter);
    }

    std::shuffle(pairs.begin(), pairs.end(),
                std::mt19937(std::random_device()()))

    for (int i = 0; i < (*table).size(); i++){
        (*table)[i] = pairs[i];
    }

    std::cout << "All available types are: ";

    for (int i = 0; i < letters.size(); i++){
        if(i == letters.size() - 1) {
            std::cout << "and " << letters[i] << ".\n\n";
        } else {
            std::cout << letters[i] << ", ";
        }
    }
}

/**
 * @brief Utility function to print the table.
 * @tparam T The type of the table.
 * @param table The table to print.
 * @returns void
 */
template <typename T>
void print_table(const std::vector<T> &table){
    std::cout <<"| ";
    std::vector<T> table_print(table.size());

    for (int i = 0; i < table.size(); i++){
        table_print[i] = ' ';

        if (table[i] != 0)
            table_print[i] = table[i];
    }

    for (int i = 0; i < table.size(); i++){
        if(i % 5 == 0 && i != 0)
            std::cout << "\n| ";

        std::cout << table_print[i] << " | ";
    }
}

// Prototype function. This is needed as `ask_data` calls `reset_data`, and
// `reset_data` calls `ask_data`.
template <typename T>
void reset_data(const std::vector<T> &, int *, int *, int *);

/**
 * @brief Function that asks the user for their
 * input in the table they previously chose.
 * @tparam T The type of the table.
 * @param table The table that's used to get the user's input and data.
 * @param answer The user's answer.
 * @param old_answer The user's previous answer.
 * @param memory_count A counter to check if the user has already answered two
 * values.
 * @returns void
 */

}

}