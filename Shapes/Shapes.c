

// 16
void shape_RightArrow(int n)
{
    int size = n / 2;
    int cnt = size;
    int cnt2 = 1;
    int cnt3 = 0;
    int cnt4 = size - 1;
    for (int j = 1; j <= size; j++)
    {
        for (int i = 1; i <= cnt3; i++)
        {
            printf(" ");
        }
        for (int i = 1; i <= cnt; i++)
        {
            printf("*");
        }
        cnt--;
        cnt3++;
        printf("\n");
    }

    for (int j = 1; j <= size; j++)
    {
        for (int i = 1; i <= cnt4; i++)
        {
            printf(" ");
        }
        for (int i = 1; i <= cnt2; i++)
        {
            printf("*");
        }

        cnt4--;
        cnt2++;
        printf("\n");
    }
}

// 15
void shape_HalfDiamond(int n)
{
    int size = n / 2;
    int cnt = 1;
    int cnt2 = size + 1;
    for (int j = 1; j <= size; j++)
    {
        for (int i = 1; i <= cnt; i++)
        {
            printf("*");
        }
        cnt++;
        printf("\n");
    }

    for (int j = 1; j <= size + 1; j++)
    {
        for (int i = 1; i <= cnt2; i++)
        {
            printf("*");
        }
        cnt2--;
        printf("\n");
    }


}



// 15
void shape_LeftArrow(int n)
{
    int size = n / 2;
    int cnt = size;
    int cnt2 = 1;
    for (int j = 1; j <= size; j++)
    {
        for (int i = 1; i <= cnt; i++)
        {
            printf("*");
        }
        cnt--;
        printf("\n");
    }

    for (int j = 1; j <= size; j++)
    {
        for (int i = 1; i <= cnt2; i++)
        {
            printf("*");
        }
        cnt2++;
        printf("\n");
    }


}
// 14
void shape_HollowSquarwithDiagonal(int n)
{
    int cnt = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if((i == cnt || i == n - cnt) || (k == 1 || k == n) || (i == 1 || i == n))
            {
                printf("*");
            }
            else
                printf(" ");
        }
        cnt++;
        printf("\n");
    }
}

// 13
void shape_HollowPyramid(int n)
{
    int cnt1 = 1;
    int cnt2 = n - 1;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= cnt2; i++)
        {
            printf(" ");
        }
        cnt2--;
        for (int j = 1; j <= cnt1; j++)
        {
            if ((j == 1 || j == cnt1) || k == n )
            {
                printf("*");
            }
            else
                printf(" ");
        }
        cnt1 += 2;
        printf("\n");
    }
}

// 12
void shape_Hut(int n)
{
    int cnt1 = 1;
    int cnt2 = n / 2 - 1;
    int size = n / 2;

    for (int k = 1; k <= size; k++)
    {
        for (int j = 1; j <= cnt2; j++)
        {
            printf(" ");
        }
        cnt2--;
        for (int i = 1; i <= cnt1; i++)
        {
            printf("*");
        }
        cnt1 += 2;


        printf("\n");
    }


    int c = cnt1 - 2;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if  (j <= (c / 3) || j > (c / 3) * 2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

}



// 11
void shape_HollowDiamond(int n)
{
    int cnt1 = n / 2 - 1;
    int cnt2 = 1;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= cnt1; i++)
        {
            printf(" ");
        }

        for (int j = 1; j <= cnt2; j++)
        {
            if(j == 1 || j == cnt2)
                printf("*");
            else
                printf(" ");
        }
        if (k < n / 2)
        {
            cnt1--;
            cnt2 +=  2;
        }
        else
        {
            cnt1++;
            cnt2 -=  2;
        }

        printf("\n");
    }

}


// 10
void shape_DiamondStar(int n)
{
    int cnt1 = n / 2 - 1;
    int cnt2 = 1;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= cnt1; i++)
        {
            printf(" ");
        }

        for (int j = 1; j <= cnt2; j++)
        {
            printf("*");
        }
        if (k < n / 2)
        {
            cnt1--;
            cnt2 +=  2;
        }
        else
        {
            cnt1++;
            cnt2 -=  2;
        }

        printf("\n");
    }

}

// 9
void shape_RhombusStar(int n)
{
    int cnt = 0;

    for (int k = 1; k <= n; k++)
    {

        for (int j = 1; j <= cnt; j++)
        {
            printf(" ");
        }
        cnt++;
        for(int i = 1; i <= n; i++)
        {
            printf("*");
        }
        printf("\n");
    }

}
// 8
void shape_ReversePyramid(int n)
{
    int cnt1 = n * 2 - 1;
    int cnt2 = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int j = 1; j <= cnt2; j++)
        {
            printf(" ");
        }
        cnt2++;


        for (int i = 1; i <= cnt1; i++)
        {
            printf("*");
        }
        cnt1 -= 2;
        printf("\n");
    }

}


// 7
void shape_PyramidStar(int n)
{
    int cnt1 = n - 1;
    int cnt2 = 1;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= cnt1; i++)
        {
            printf(" ");
        }
        cnt1--;
        for (int j = 1; j <= cnt2; j++)
        {
            printf("*");
        }
        cnt2 +=  2;
        printf("\n");
    }


}

// 6
void shape_ReversedMirroredRightTriangle(int n)
{
    int cnt1 = n;
    int cnt2 = 0;


    for (int k = 1; k <= n; k++)
    {
        for (int j = 1; j <= cnt2; j++)
        {
            printf(" ");
        }
        for (int i = 1; i <= cnt1; i++)
        {
            printf("*");
        }
        cnt1--;

        cnt2++;
        printf("\n");
    }
}

// 5
void shape_MirroredRightTriangle(int n)
{
    int cnt1 = n - 1;
    int cnt2 = 1;


    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= cnt1; i++)
        {
            printf(" ");
        }
        cnt1--;
        for (int j = 1; j <= cnt2; j++)
        {
            printf("*");
        }
        cnt2++;
        printf("\n");
    }

}

// 4
void shape_ExponentiallyIncrease(int n)
{
    int cnt = 1;

    for(int j = 1; j <= n; j++)
    {
        for (int i = 1 ; i <= cnt; i++)
        {
            printf("*");
        }
        cnt *= 2;
        printf("\n");
    }
}



// 3
void shape_HollowSquare(int n)
{
    for(int j = 1; j <= n; j++)
    {


        for (int i = 1; i <= n; i++)
        {


            if (j == 1 || j == n)
            {
                printf("*");
            }
            else if(i == 1 || i == n)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// 2
void shape_InvertedRightTriangle(int n)
{
    int cnt = n;

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= cnt; i++)
        {
            printf("*");
        }
        cnt--;
        printf("\n");
    }


}
// 1
void shape_rightTriangle(int n)
{
    for (int j = 1; j <= n; j++)
    {


        for (int i = 1; i <= j; i++)
        {
            printf("*");
        }
        printf("\n");
    }
}


