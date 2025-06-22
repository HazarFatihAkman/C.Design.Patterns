# Design Patterns are in C

This repo is for practicing Design Patterns in C.

## Singleton - Creational Pattern

### What's Singleton Design Pattern?

This pattern aims to create only one instance and use it throughout the entire project without re-creating or changing. We use this pattern with `static` keyword and function-level scope. Also you should pay attention this singleton instance not changing in anywhere cause you can use the same singleton instance in different threads and if you make change in somewhere, it'll not be thread-safety usage and you'll face bugs. Important things are always understand concept correctly and use this in your projects with right ways.

#### Real World Example

You have something like Config or Logger in your project. You don't change your configs or logger system in runtime. So everytime you use Config or Logger, you don't have to re-create the same object. You just need to create one global instance and use it. You can use this in different ways in other languages.

### Example

```c
static config_manager_t* get_instance(pthread_mutex_t *lock) {
    if (config_manager == NULL) {
        pthread_mutex_lock(lock);
        config_manager = (config_manager_t*) calloc(1, sizeof(config_manager_t));
        if (config_manager == NULL) {
            fprintf(stderr, "Memory Allocation!\n");
            return NULL;
        }
        set_config();
        pthread_mutex_unlock(lock);
    }

    return config_manager;    
}
```

## Factory Method - Creational Pattern

### What's Factory Method?

When we don't know which class is needed at compile time, we use factory method. This pattern allows you to create objects that has unique behaviours without specifying exact class. You define a common abstract class(need shared logic or fields) or interface(no shared code) for a family of related objects. Other classes should get implemented or extended by this base type with overriding methods. Main logic is creating and return the appropriate subclass. This pattern helps centralize object creation, flexibility and scalability.

#### Real World Example

You're creating a car tracking app. The app needs to track different types of cars like SUVs, Sedans and etc. each with unique behaviours (for example; SUV may need off-road tracking, while Sedan may focus on city routes). You define a common base (for example; a Car abstract class or ICar interface) and create subclasses for each vehicle type, but instead of creating those objects directly we use a factory class that can return the correct car type based on some input like user selection or vehicle data. Factory Method will make your app flexible and open to future types like Electric Cars or Hybrids and more without changin the core logic.

### Example

```c

static logistic_t create_logistic(LOGISTIC_TYPE type) {
    switch (type) {
        case SEA: return sea_const;
        case ROAD: return road_const;
        default: break;
    }
}

const struct logistic_factory logistic_factory = { .create_logistic = &create_logistic };

```

## Builder - Creational Pattern

### What's Builder Pattern?

If you have a constructor with 10+ parameters and you want to code it with different way. Builder Pattern is what you look for exactly. Builder Pattern provides you to create objects from builder class and it's more readable and flexible than constructor with 10+ parameters. You can validate every parameter when it's set and also when you build an object you can also validate them again to be sure everything is alright.Common usages are Validators(for example; null->max_len), PDF reports, HTML reports or JSON reports (for example; title->body->footer).

#### Real World Example

You're building an object like User, Product or etc. with optional properties. Let's say you have Product and you just need id, product name and image sources for the category page, but your constructor looks like:
```c
typedef char* str;
typedef struct product {
    uuid_t id;
    uuid_t category_id;
    str brand;
    str name;
    str* image_src;
    double price;
    //etc.
} product_t;

product_t* product(uuid_t id, uuid_t category_id, str brand, str name, str* image_src, double price...);

```
Instead of repeating this full constructor every time, you may want to create a `Product` light-weight object that's already filtered on the server and sent to the client. In this case, you can create builder for it and use it instead of calling the constructor with all requried parameters.

#### Example
```c
product_t* apple_ = product_builder
        ->id(product_builder, (uuid_t)"00000000-0000-0000-0000-000000000000")
        ->brand(product_builder, "Apple")
        ->name(product_builder, "Macbook Pro M3 Pro 14 inch")
        ->image_src(product_builder, (char**) {"Apple_Macbook_Pro_M3_Pro_14_inch_1.webp","Apple_Macbook_Pro_M3_Pro_14_inch_2.webp"})
        ->build(product_builder);
```