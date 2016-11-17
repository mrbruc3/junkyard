#include <sys/types.h> 
#include <unistd.h>
#include <sys/eventfd.h>

#include <iostream>

int main(int argc, char *argv[])
{
    int fd = eventfd(0, 0);

    pid_t pid = fork();

    if (pid != 0)
    {
        std::cout << "wait for signal" << std::endl;

        uint64_t item;
        ssize_t bytes = read(fd, &item, sizeof(uint64_t));

        if (bytes != sizeof(uint64_t))
        {
            std::cerr << "error during read" << std::endl;
        }

        std::cout << "parent: recv from child " << item << std::endl;
    }
    else
    {
        sleep(5);

        uint64_t item = 12;
        ssize_t bytes = write(fd, &item, sizeof(uint64_t));

        if (bytes != sizeof(uint64_t))
        {
            std::cerr << "error during read" << std::endl;
        }

        std::cout << "child: write to parent" << std::endl;
        
        sleep(5);

        std::cout << "child: end" << std::endl;
    }

    return 0;
}
