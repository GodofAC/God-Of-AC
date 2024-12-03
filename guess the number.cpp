#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

void playGame() {
    std::srand(std::time(0)); // 난수 생성 시드 설정
    int target = std::rand() % 100 + 1; // 1부터 100 사이의 난수 생성
    int guess = 0;
    int attempts = 0;

    std::cout << "1부터 100 사이의 숫자를 맞춰보세요!" << std::endl;

    while (guess != target) {
        std::cout << "숫자를 입력하세요: ";
        while (!(std::cin >> guess)) {
            std::cin.clear(); // 입력 스트림을 초기화
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 잘못된 입력 무시
            std::cout << "유효한 숫자를 입력하세요: ";
        }
        attempts++;

        if (guess < target) {
            std::cout << "더 큰 숫자입니다." << std::endl;
        } else if (guess > target) {
            std::cout << "더 작은 숫자입니다." << std::endl;
        } else {
            std::cout << "정답입니다! 시도 횟수: " << attempts << std::endl;
        }
    }
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        playGame();
        std::cout << "다시 하시겠습니까? (y/n): ";
        std::cin >> playAgain;
        while (std::cin.fail() || (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "유효한 입력이 아닙니다. 다시 하시겠습니까? (y/n): ";
            std::cin >> playAgain;
        }
    }
    return 0;
}