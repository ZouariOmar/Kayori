/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: zouari_omar
* @update: 04/24/24
? @file:   enigma.h
----------------------------------------------- */

#ifndef __ENIGMA_H__
#define __ENIGMA_H__

//? --------------------- STRUCT PROTOTYPE DECLARATION PART ----------------------
typedef struct Enigma {
    char qcm[MAX_PATH],
        op1[MAX_PATH],
        op2[MAX_PATH],
        op3[MAX_PATH];
    int answer;
} eg;

//? -------------------- FUNCTIONS PROTOTYPE DECLARATION PART --------------------
/*
? enigma() void fn
* this fun generate random qcm
* this fun have a @timer
*/
void enigma();

/*
? initEnigma(surface sub) void fn
* this fun blit the first viewed imgs
*/
void initEnigma(surface *, TTF_Font *, eg);

/*
? -- scanEnigma(char *path, eg *e, int line) void fn --
* scan all the enigma info depending on the line var
*/
void scanEnigma(char *, eg *, int);

/*
? void scroll_LR(surface* sub, int* usrOpPos, int direction) void fn
* scroll between the between the @false_option (enemy head) and the @correct_option (kayori_head)
*/
void scroll_LR(surface*, int*, int);

/*
? void scroll_LR(surface* sub, int* usrOpPos, int direction) void fn
* display && change the color of the qcm and also the @timer_bar
*/
void qcm(surface *, int *);

#endif
