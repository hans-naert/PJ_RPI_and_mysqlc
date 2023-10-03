#include "PJ_RPI.h"
#include <stdio.h>
#include "mariadb/mysql.h"

int main()
{
    MYSQL *con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "root_pswd", NULL, 0, NULL, 0) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    if (mysql_query(con, "CREATE DATABASE testdb"))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    mysql_close(con);

    if (map_peripheral(&gpio) == -1)
    {
        printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
        return -1;
    }

    // Define gpio 17 as output
    INP_GPIO(17);
    OUT_GPIO(17);

    while (1)
    {
        // Toggle 17 (blink a led!)
        GPIO_SET = 1 << 17;
        sleep(1);

        GPIO_CLR = 1 << 17;
        sleep(1);
    }

    return 0;
}