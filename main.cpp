#include <iostream>

bool getLineInputCorrectness (std::string linesSum)
{
    if (linesSum.length() != 9) return false;

    for (int i = 0; i < linesSum.length(); i++)
    {
        if (linesSum[i] != 'O' && linesSum[i] != 'X' && linesSum[i] != '.') return false;
    }
    return true;
}

int getWinCombinationsCount(char playerSymbol, std::string linesSum)
{
    int winCombinationsCount = 0;

    if (linesSum[0] == playerSymbol && linesSum[4] == playerSymbol && linesSum[8] == playerSymbol) winCombinationsCount++;
    if (linesSum[2] == playerSymbol && linesSum[4] == playerSymbol && linesSum[6] == playerSymbol) winCombinationsCount++;
    if (linesSum[0] == playerSymbol && linesSum[1] == playerSymbol && linesSum[2] == playerSymbol) winCombinationsCount++;
    if (linesSum[3] == playerSymbol && linesSum[4] == playerSymbol && linesSum[5] == playerSymbol) winCombinationsCount++;
    if (linesSum[6] == playerSymbol && linesSum[7] == playerSymbol && linesSum[8] == playerSymbol) winCombinationsCount++;
    for (int i = 0; i < 3; i++)
    {
        if ((linesSum[i] == playerSymbol && linesSum[i+3] == playerSymbol && linesSum[i+6] == playerSymbol)) winCombinationsCount++;
    }
    return winCombinationsCount;
}

int getSymbolCount(char symbol, std::string linesSum)
{
    int symbolCount = 0;
    for (int i = 0; i < linesSum.length(); i++)
    {
        if (linesSum[i] == symbol) symbolCount++;
    }
    return symbolCount;
}

std::string getGameStatus(std::string linesSum)
{
    if (!getLineInputCorrectness(linesSum)) return "ERROR - wrong symbols are used\n";

    int crossesWinCombinations = getWinCombinationsCount('X', linesSum);
    int zerosWinCombinations = getWinCombinationsCount('O', linesSum);
    if (crossesWinCombinations > 1) return "ERROR - several winning combinations for crosses.\n";
    else if (zerosWinCombinations > 1) return "ERROR - several winning combinations for zeros.\n";
    else
    {
        int crosses = getSymbolCount('X', linesSum);
        int zeros = getSymbolCount('O', linesSum);
        int dots = getSymbolCount('.', linesSum);
        bool crossesAreWinners = crossesWinCombinations == 1;
        bool zerosAreWinners = zerosWinCombinations == 1;
        bool gameIsNotFinished = !crossesAreWinners && !zerosAreWinners;

        if (crossesAreWinners && zerosAreWinners) return "ERROR - several winners.\n";
        else if (zerosAreWinners && crosses > zeros) return "ERROR - too many crosses (zeros are winners)\n";
        else if (crossesAreWinners && zeros >= crosses) return "ERROR - too many zeros (crosses are winners)\n";
        else if (std::abs(crosses - zeros) > 1) return "ERROR - incorrect number of crosses / zeros\n";
        else if (crossesAreWinners) return "GAME IS FINISHED: Petya won!\n";
        else if (zerosAreWinners) return "GAME IS FINISHED: Vanya won!\n";
        else if (dots == 0) return "GAME IS FINISHED: no winners\n";
        else if (gameIsNotFinished) return "GAME IS IN PROCESS...\n";
    }

  return "RES";
}

int main() {
    std::string line_1;
    std::string line_2;
    std::string line_3;
    std::cout << "Enter 3 lines with 3 symbols length(symbols allowed: 'O', 'X', '.'):\n";
    std::cin >> line_1;
    std::cin >> line_2;
    std::cin >> line_3;

    std::string linesSum = line_1 + line_2 + line_3;

    std::cout << getGameStatus(linesSum);

    return 0;
}
