#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE childProcess;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create the child process
    if (CreateProcess(NULL, "child.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        // Wait for the child process to complete
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        printf("Parent Process (Prime Numbers):\n");

        int i, j, is_prime;

        for (i = 2; i <= 30; i++) {
            is_prime = 1;

            for (j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    is_prime = 0;
                    break;
                }
            }

            if (is_prime)
                printf("%d ", i);
        }

        printf("\n");
    } else {
        fprintf(stderr, "CreateProcess failed\n");
        return 1;
    }

    return 0;
}

