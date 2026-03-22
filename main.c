#include <3ds.h>
#include <stdio.h>

int main() {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    printf("BR PATCH STORE 3DS\n");
    printf("------------------\n");
    printf("A: Baixar patches\n");
    printf("B: Backup saves\n");
    printf("START: Sair\n");

    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_START) break;

        if (kDown & KEY_A) {
            printf("\nBaixando patches...\n");
        }

        if (kDown & KEY_B) {
            printf("\nBackup de saves...\n");
        }

        gspWaitForVBlank();
        gfxFlushBuffers();
        gfxSwapBuffers();
    }

    gfxExit();
    return 0;
}
