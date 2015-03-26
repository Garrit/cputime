/*
 * Run the command and measure the user CPU time it consumes.
 *
 * Outputs to stderr one line with the integer number of milliseconds of user
 * CPU time consumed by the program it launches.
 *
 * Author: Samuel Coleman <samuel@seenet.ca>
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s command [args]\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Declare all variables involved in timing ahead of time. Because hey,
     * creating some stack variables is totally going to affect time, right? */
    int status;
    struct rusage start_usage;
    struct rusage end_usage;
    struct timeval consumed_time;

    pid_t child = fork();
    if (child < 0)
    {
        fprintf(stderr, "Failed to fork.");
        return EXIT_FAILURE;
    }
    else if (child == 0)
    {
        execvp(argv[1], &argv[1]);
        fprintf(stderr, "Could not execute %s.\n", argv[1]);
        return EXIT_FAILURE;
    }

    /* Assume that it takes essentially zero time to resume execution in the
     * parent process after forking. We don't want to start measuring before the
     * fork because that might minisculely penalize the child for the time taken
     * to fork. */
    getrusage(RUSAGE_CHILDREN, &start_usage);
    waitpid(child, &status, 0);
    getrusage(RUSAGE_CHILDREN, &end_usage);

    timersub(&end_usage.ru_utime, &start_usage.ru_utime, &consumed_time);
    fprintf(stderr, "%ld\n",
        (consumed_time.tv_sec * 1000000 + consumed_time.tv_usec) / 1000);

    return status;
}