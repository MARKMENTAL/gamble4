#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int get_chips() {
	int chips = 1000 + rand() % 400;
	return chips;
}

int game(int chips) {
	int cpunumber = rand() % 4;
	int number = 0;
	int bet = 0;
	printf("Current Chip Balance: %d\n", chips);
	printf ("Enter a number to compare to bet on: 0 to 4 \n");
        scanf("%d", &number);
	printf("Enter your bet. You have %d chips\nMinimum bet is 100.\n", chips);
	scanf("%d", &bet);
	if (bet > chips){
		bet = chips;
	}

	if (bet < 100){
		bet = 100;
	}

        if (number == cpunumber) {
                printf("You win!\nPlayer:%d\nCPU:%d\n", number, cpunumber);
		chips = chips + bet;
        }
        else{
                printf("You lose!\nPlayer:%d\nCPU:%d\n", number, cpunumber);
		chips = chips - bet;
        }
	return chips;
}

int main() {
	srand(time(NULL));
	int chips = get_chips();
	//printf("Current Chip Balance: %d\n", chips);
	int running = 1;
	while (running == 1){
		if (chips > 100){
			chips = game(chips);
		}
		else {
			printf("Leave the casino! You don't have enough chips to play.\n");
			running = 0;
		}
	}
	return 0;
}
