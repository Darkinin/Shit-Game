#include <stdio.h>

void readmap(void);
void drawmap(void);
void movement();
void writescreen();

int blocks[100][15];
int i, m, x, y = 0;

main() {
	
	extern i, j;
	
	readmap();
	
	/* Write the map to the screen at game start */
	writescreen();
	
	while (i == 0) {
		/* initialiaze main gameplay */
		
		movement();
	}
	
	printf("Thank you for playing!\n");
	
	return 0;
}

void readmap(void) {
	
	extern blocks[100][15];
	FILE *mapfile;
	int c, j, k;
	
	mapfile = fopen("map002", "r");
	
	for (k = 0; k < 15; k++) {
		
		for (j = 0; j < 100; j++) {
			
			if ((c = fgetc(mapfile)) != '\n' && c != EOF) {
				
				blocks[j][k] = c;
			}
			
			else if(c == '\n') {
				
				break;
			}
		}
	}
		
	fclose(mapfile);
}

void movement() {
	
	extern i, m, x, y;
	int direction = 0;
	char c;
	
	while (m == 0) {
		
		c = getchar();
		
		if (c == 'e') {
			
			if (blocks[(1 + x)][(1 + y)] != '|' && blocks[(1 + x)][(1 + y)] != '_') {
				
				y--;
				
				direction = 1;
			}
		}
		
		else if (c == 's') {
			
			if (blocks[x][(2 + y)] != '|' && blocks[x][(2 + y)] != '_') {
				
				x--;
				
				direction = 3;
			}
		}
		
		else if(c == 'd') {
			
			if (blocks[(1 + x)][(3 + y)] != '|' && blocks[(1 + x)][(3 + y)] != '_') {
				
				y++;
				
				direction = 2;
			}
		}
		
		else if(c == 'f') { 
			
			if (blocks[(2 + x)][(2 + y)] != '|' && blocks[(2 + x)][(2 + y)] != '_') {
				
				x++;
				
				direction = 4;
			}
		}
		
		else if(c == 'q') {
			
			m++;
			
			goto end;
		}
		
		writescreen();
		
		end:
		;
	}
	
	i++;
}

void writescreen() {
	
	extern int x, y;
	int c;
	
	c = blocks[(1 + x)][(2 + y)];
	blocks[(1 + x)][(2 + y)] = 'A';
	
	drawmap();
	
	if (m == 0) {
		
		printf("%d x, %d y\n", x, y);
		
		blocks[(1 + x)][(2 + y)] = c;
	}
}

void drawmap(void) {
	
	extern blocks[100][15], m;
	int i, j;
	
	system("clear");
	
	/* draw the map from the blocks array */
	for (i = 0; i < 15; i++) {
		
		for (j = 0; j < 100; j++) {
			
			if (blocks[j][i] != '\n' && blocks[j][i] != EOF) {
				
				printf("%c", blocks[j][i]);
			}
			
			else if (blocks[j][i] == '\n') {
				
				break;
			}
		}
		
		printf("\n");
	}
	
	if (blocks[50][9] != 'A') {
		
		;
	}
	
	else if (blocks[50][9] == 'A') {
		
		printf("You have won the game!\n");
		
		m++;
	}
}
