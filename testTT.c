#include <stdio.h>
#include <string.h>

#ifdef _WIN32
    // For Windows
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib") // Link with ws2_32.lib

    int initialize_winsock() {
        WSADATA wsa;
        return WSAStartup(MAKEWORD(2, 2), &wsa);
    }

    void cleanup_winsock() {
        WSACleanup();
    }

#else
    // For Unix/Linux/macOS
    #include <netdb.h>
    #include <arpa/inet.h>
    #include <unistd.h>

    int initialize_winsock() { return 0; }  // Dummy for non-Windows
    void cleanup_winsock() {}              // Dummy for non-Windows
#endif

int domain_exists(const char *domain) {
    struct hostent *host = gethostbyname(domain);
    return (host != NULL);
}

int main() {
    char domain[100];

    printf("Enter domain to check (e.g. google.com): ");
    fgets(domain, sizeof(domain), stdin);

    // Remove newline if present
    size_t len = strlen(domain);
    if (domain[len - 1] == '\n') domain[len - 1] = '\0';

    // Initialize networking (only affects Windows)
    if (initialize_winsock() != 0) {
        printf("Failed to initialize networking (Windows only).\n");
        return 1;
    }

    if (domain_exists(domain)) {
        printf("✅ Domain '%s' exists and resolves.\n", domain);
    } else {
        printf("❌ Domain '%s' does not resolve (may not exist).\n", domain);
    }

    // Clean up Winsock (Windows only)
    cleanup_winsock();

    return 0;
}
