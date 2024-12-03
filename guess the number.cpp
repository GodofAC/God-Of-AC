#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

void playGame() {
    std::srand(std::time(0)); // ���� ���� �õ� ����
    int target = std::rand() % 100 + 1; // 1���� 100 ������ ���� ����
    int guess = 0;
    int attempts = 0;

    std::cout << "1���� 100 ������ ���ڸ� ���纸����!" << std::endl;

    while (guess != target) {
        std::cout << "���ڸ� �Է��ϼ���: ";
        while (!(std::cin >> guess)) {
            std::cin.clear(); // �Է� ��Ʈ���� �ʱ�ȭ
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �߸��� �Է� ����
            std::cout << "��ȿ�� ���ڸ� �Է��ϼ���: ";
        }
        attempts++;

        if (guess < target) {
            std::cout << "�� ū �����Դϴ�." << std::endl;
        } else if (guess > target) {
            std::cout << "�� ���� �����Դϴ�." << std::endl;
        } else {
            std::cout << "�����Դϴ�! �õ� Ƚ��: " << attempts << std::endl;
        }
    }
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        playGame();
        std::cout << "�ٽ� �Ͻðڽ��ϱ�? (y/n): ";
        std::cin >> playAgain;
        while (std::cin.fail() || (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "��ȿ�� �Է��� �ƴմϴ�. �ٽ� �Ͻðڽ��ϱ�? (y/n): ";
            std::cin >> playAgain;
        }
    }
    return 0;
}