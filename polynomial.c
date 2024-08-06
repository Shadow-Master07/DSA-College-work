#include <stdio.h>
#include <stdlib.h>

typedef struct polynomialData
{
    float coefficient;
    int exponent;
    struct polynomialData *next;
} s_polyData;

void addToLinkedList(s_polyData *head)
{
    s_polyData *temp = head;
    while (1)
    {
        printf("Coefficient: ");
        scanf("%f", &(temp->coefficient));
        printf("Exponent: ");
        scanf("%d", &(temp->exponent));

        if (temp->exponent > 0)
        {
            temp->next = (s_polyData *)malloc(sizeof(s_polyData));
            temp = temp->next;
        }
        else
        {
            temp->next = NULL;
            return;
        }
    }
}

void addPolynomials(s_polyData *head1, s_polyData *head2, s_polyData *finalHeadTemp)
{
    s_polyData *temp1 = head1, *temp2 = head2, *finalHead = finalHeadTemp;
    while (1)
    {
        if ((temp1 != NULL) && (temp2 == NULL))
        {
            finalHead->coefficient = temp1->coefficient;
            finalHead->exponent = temp1->exponent;
            finalHead->next = (s_polyData *)malloc(sizeof(s_polyData));
            temp1 = temp1->next;
        }
        if ((temp1 == NULL) && (temp2 != NULL))
        {
            finalHead->coefficient = temp2->coefficient;
            finalHead->exponent = temp2->exponent;
            finalHead->next = (s_polyData *)malloc(sizeof(s_polyData));
            temp2 = temp2->next;
        }
        if ((temp1 == NULL) && (temp2 == NULL))
        {
            finalHead->next = NULL;
            finalHead->coefficient = 0;
            finalHead->exponent = 0;
            return;
        }
        if (temp1->exponent == temp2->exponent)
        {
            finalHead->coefficient = temp1->coefficient + temp2->coefficient;
            finalHead->exponent = temp1->exponent;
            finalHead->next = (s_polyData *)malloc(sizeof(s_polyData));
            finalHead = finalHead->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
            continue;
        }
        if (temp1->exponent > temp2->exponent)
        {
            finalHead->coefficient = temp1->coefficient;
            finalHead->exponent = temp1->exponent;
            finalHead->next = (s_polyData *)malloc(sizeof(s_polyData));
            temp1 = temp1->next;
            continue;
        }
        if (temp1->exponent < temp2->exponent)
        {
            finalHead->coefficient = temp2->coefficient;
            finalHead->exponent = temp2->exponent;
            finalHead->next = (s_polyData *)malloc(sizeof(s_polyData));
            temp2 = temp1->next;
            continue;
        }
    }
}

void showPolynomial(s_polyData *head)
{
    for (s_polyData *temp = head; temp != NULL; temp = temp->next)
    {
        printf("%f, %d, %x\n", temp->coefficient, temp->exponent, temp->next);
    }
}

int main()
{
    s_polyData *head1 = NULL;
    s_polyData *head2 = NULL;

    printf("----------------------\n");
    printf("First polynomial entry\n");
    head1 = (s_polyData *)malloc(sizeof(s_polyData));
    addToLinkedList(head1);

    printf("----------------------\n");
    printf("Second polynomial entry\n");
    head2 = (s_polyData *)malloc(sizeof(s_polyData));
    addToLinkedList(head2);

    printf("----------------------\n");
    showPolynomial(head1);
    printf("----------------------\n");
    showPolynomial(head2);

    s_polyData *final = (s_polyData *)malloc(sizeof(s_polyData));
    addPolynomials(head1, head2, final);
    printf("----------------------\n");
    showPolynomial(final);

    return 0;
}