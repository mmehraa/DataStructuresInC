void deleteRear(){
        int temp;
        if (front == -1 ){
                printf("Dequeue is Empty.");
                return;
        }
        else {
                temp = deQueue[rear]
                if (rear == 0){
                        rear = MAX - 1;
                }
                else {
                        rear++;
                }
        }
}

void insertFront(){
        if (front == 0 && rear == MAX - 1 || front = rear + 1){
                printf("Dequeue is Full.");
        }
        else {
                if (front == 0) {
                        front = MAX - 1;
                }
                else {
                        front--;
                }
                deQueue[front] = item;
        }
}