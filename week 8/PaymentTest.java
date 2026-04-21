public class PaymentTest {
    public static void main(String[] args) {
        PaymentGateway pg1 = new CreditCardPayment();
        pg1.pay(5000);
        pg1.refund(1000);
        PaymentGateway pg2 = new UPIPayment();
        pg2.pay(3000);
        pg2.refund(500);
    }
}