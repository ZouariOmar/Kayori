// by_kayori_Nova_Grp
// 01/24/24
// kayori :: main.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "../lib/lib.c"
                    /* MAIN() INT FUNCTION DEV PART */
int main(int argc, char *argv[]) {
	SDL_version nb;
	SDL_VERSION(&nb);
    printf(
        "Hello World !\n"
	    "%d.%d.%d\n", nb.major, nb.minor, nb.patch);
    // rest_of_code
	return 0;
}