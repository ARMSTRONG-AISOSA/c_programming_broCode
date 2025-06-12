#include <stdio.h>
#include <string.h>

#ifdef _WIN32
// Windows headers and libraries
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

int initialise_winsock()
{
    WSADATA wsa;
    return WSAStartup(MAKEWORD(2, 2), &wsa);
}

void cleanup_winsock()
{
    WSACleanup();
}

#else
// Linux/masOS headers
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int initialise_winsock()
{
    return 0;
}

void cleanup_winsock() {}
#endif

// ANSI ESCAPE CODES
#define ANSI_BOLD "\x1b[1m" // bold text

#define ANSI_COLOR_YELLOW "\x1b[33m" // yellow text
#define ANSI_COLOR_BLACK "\x1b[30m"  // black test
#define ANSI_BG_WHITE "\x1b[47m"     // white bg
#define ANSI_RESET "\x1b[0m"         // reset to default

// Function
int resolve_and_print_ips(const char *domain)
{
    struct hostent *host = gethostbyname(domain);
    if (!host) // if host not found
    {
        return 0;
    }

    printf("\n✅ Domain " ANSI_BOLD"'%s'"ANSI_RESET, domain);
    printf(" exists.\n");
    printf("📡 Resolved IP addresses:\n");

    char **addr_list = host->h_addr_list;
    for (int i = 0; addr_list[i] != NULL; i++)
    {
        struct in_addr *addr = (struct in_addr *)addr_list[i];
        printf("  ➤ %s\n", inet_ntoa(*addr));
    }

    return 1;
}

int main()
{
    char domain[100];

    printf("\n" ANSI_COLOR_YELLOW ANSI_BOLD"====Starting Domain Resolver Program====" ANSI_RESET "\n\n");

    usleep(500000); // delay by .5sec

    printf("Enter domain to check (e.g. google.com): " ANSI_BG_WHITE ANSI_COLOR_BLACK);
    fgets(domain, sizeof(domain), stdin);
    printf(ANSI_RESET"\b \b");

    // Remove newline
    domain[strlen(domain) - 1] = '\0';

    int int_win_value = initialise_winsock(); // Call function & store value
    if (int_win_value != 0)                   // if returned value is not '0'
    {
        printf("❌ Failed to initialize networking.\n");
        return 1; // failed
    }

    int int_res_value = resolve_and_print_ips(domain);

    if (!int_res_value) // Not true; i.e returned '0'
    {
        printf("❌ Domain '%s' could not be resolved.\n", domain);
    }

    cleanup_winsock(); // Clean up when all is done

    return 0;
}