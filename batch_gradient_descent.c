#include <stdio.h>

int main(void)
{
    int m = 4, n = 2, max_iteration = 5000;
    float loss = 1000.0; /* initialize a big loss */

    float matrix[4][2] = {{1, 4}, {2, 5}, {5, 1}, {4, 2}};
    float result[4] = {19, 26, 19, 20};
    float theta[2] = {2, 3};     /* initialized theta {2, 3}, model theta is {3, 4} */
    float error_sum[2] = {0, 0};
    float learning_rate = 0.001; /* leaning_rate must be small enough */

    for(int iteration = 0; iteration < max_iteration && loss > 0.0001; ++iteration)
    {
        for(int i = 0; i < m; ++i) {
            float hypothesis = 0;
            for(int j = 0; j < n; ++j) {
                hypothesis += matrix[i][j] * theta[j];
            }
            for(int j = 0; j < n; ++j) {
                error_sum[j] += (result[i] - hypothesis) * matrix[i][j];
            }
        }
        for(int j = 0; j < n; ++j) {
            theta[j] += learning_rate * (error_sum[j]);
        }

        printf("\niteration: %d; theta: %f, %f\n", iteration, theta[0], theta[1]);

        loss = 0.0;
        for(int i = 0; i < m; ++i) {
            float sum = 0.0;
            for(int j = 0; j < n; ++j) {
                sum += matrix[i][j] * theta[j];
            }
            loss += (sum - result[i]) * (sum - result[i]);
        }
        printf("loss: %f\n", loss);
    }

    return 0;
}

