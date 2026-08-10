#include <iostream>
#include <string>
#include <vector>

class Delivery
{
public:
    Delivery(const std::string& address, double weight)
        : address_(address),
          weight_(weight)
    {
    }

    virtual ~Delivery() = default;

    void process() const
    {
        std::cout << "\nТип доставки: "
                  << getType()
                  << '\n';

        if (!validate())
        {
            std::cout << "Некоректні дані замовлення.\n";
            return;
        }

        std::cout << "Адреса: " << address_ << '\n';
        std::cout << "Вага: " << weight_ << " кг\n";
        std::cout << "Вартість: "
                  << calculatePrice()
                  << " грн\n";
        std::cout << "Термін: "
                  << getDeliveryDays()
                  << " днів\n";
    }

    virtual std::string getType() const = 0;

protected:
    virtual bool validate() const
    {
        return !address_.empty() && weight_ > 0;
    }

    virtual double calculatePrice() const = 0;
    virtual int getDeliveryDays() const = 0;

    double getWeight() const
    {
        return weight_;
    }

private:
    std::string address_;
    double weight_;
};

class CourierDelivery : public Delivery
{
public:
    CourierDelivery(const std::string& address, double weight)
        : Delivery(address, weight)
    {
    }

    std::string getType() const override
    {
        return "Кур'єрська доставка";
    }

protected:
    bool validate() const override
    {
        return Delivery::validate() && getWeight() <= 30;
    }

    double calculatePrice() const override
    {
        return 100 + getWeight() * 20;
    }

    int getDeliveryDays() const override
    {
        return 1;
    }
};

class PostOfficeDelivery : public Delivery
{
public:
    PostOfficeDelivery(const std::string& address, double weight)
        : Delivery(address, weight)
    {
    }

    std::string getType() const override
    {
        return "Доставка у відділення";
    }

protected:
    bool validate() const override
    {
        return Delivery::validate() && getWeight() <= 100;
    }

    double calculatePrice() const override
    {
        return 50 + getWeight() * 10;
    }

    int getDeliveryDays() const override
    {
        return 3;
    }
};

class ParcelLockerDelivery : public Delivery
{
public:
    ParcelLockerDelivery(const std::string& address, double weight)
        : Delivery(address, weight)
    {
    }

    std::string getType() const override
    {
        return "Доставка у поштомат";
    }

protected:
    bool validate() const override
    {
        return Delivery::validate() && getWeight() <= 20;
    }

    double calculatePrice() const override
    {
        return 70;
    }

    int getDeliveryDays() const override
    {
        return 2;
    }
};

int main()
{
    CourierDelivery courier("вул. Лісова, 10", 5.0);
    PostOfficeDelivery postOffice("Відділення №15", 25.0);
    ParcelLockerDelivery parcelLocker("Поштомат №2034", 3.5);
    CourierDelivery invalidCourier("вул. Центральна, 7", 50.0);

    std::vector<const Delivery*> deliveries{
        &courier,
        &postOffice,
        &parcelLocker,
        &invalidCourier
    };

    for (const Delivery* delivery : deliveries)
    {
        delivery->process();
    }

    return 0;
}