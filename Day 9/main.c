#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char question[256];
    char options[4][256];
    int correctOption;
} QuizQuestion;

void displayQuestion(QuizQuestion q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

void takeQuiz(QuizQuestion questions[], int numQuestions) {
    int userAnswer;
    int score = 0;

    for (int i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d:\n", i + 1);
        displayQuestion(questions[i]);

        printf("Your answer (1-4): ");
        scanf("%d", &userAnswer);

        if (userAnswer < 1 || userAnswer > 4) {
            printf("Invalid answer. Please choose a number between 1 and 4.\n");
            i--;
            continue;
        }

        if (userAnswer - 1 == questions[i].correctOption) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong. The correct answer was %d. %s\n", questions[i].correctOption + 1, questions[i].options[questions[i].correctOption]);
        }
    }

    printf("\nQuiz Over! Your score: %d/%d\n", score, numQuestions);
}

int main() {
    QuizQuestion questions[] = {
        {
            "What is the capital of France?",
            {"Berlin", "Madrid", "Paris", "Rome"},
            2
        },
        {
            "What is 2 + 2?",
            {"3", "4", "5", "6"},
            1
        },
        {
            "Which planet is known as the Red Planet?",
            {"Earth", "Mars", "Jupiter", "Saturn"},
            1
        },
        {
            "Who wrote 'To Kill a Mockingbird'?",
            {"Harper Lee", "Mark Twain", "Ernest Hemingway", "J.K. Rowling"},
            0
        }
    };

    int numQuestions = sizeof(questions) / sizeof(questions[0]);

    printf("Welcome to the Quiz Game!\n");
    takeQuiz(questions, numQuestions);

    return 0;
}
