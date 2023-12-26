#include <stdio.h>

int main() {
    // 声明变量
    float principal_amt, rate_of_interest, days, interest;
    const int yearInDays = 365; // 用于转换利率的常量

    // 提示用户输入贷款金额
    printf("输入贷款金额 (输入 0 退出): ");
    scanf("%f", &principal_amt);

    // 主循环用于处理贷款
    while ((int)principal_amt != 0) 
    {
        // 提示用户输入利率
        printf("输入利率: ");
        scanf("%f", &rate_of_interest);

        // 提示用户输入贷款期限（天）
        printf("输入贷款期限（天）: ");
        scanf("%f", &days);

        // 计算利息
        interest = (principal_amt * rate_of_interest * days) / yearInDays;

        // 显示利息金额
        printf("利息金额为 $%.2f\n", interest);

        // 提示用户输入下一个贷款金额
        printf("\n\n输入贷款金额 (输入 0 退出): ");
        scanf("%f", &principal_amt);
    }

    return 0;
}
