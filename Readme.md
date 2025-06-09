# Design Patterns are in C

This repo is for practicing Design Patterns in C.

## Singleton - Creational Pattern

When we need only one instance, we use singleton design pattern.

### What's Singleton Design Pattern?

This pattern is aiming to create only one instance and use this in everywhere of project without re-creating or changing.

#### Real World Example

You have something like Config or Logger in your project. You don't change your configs or logger system in runtime. So everytime you use Config or Logger, you don't have to re-create the same object. You just need to create one global instance and use it. You can use this in different ways in other languages.

#### Example of Asp.Net Core (Dependency Injection)

```c#
builder.Services.AddSingleton<IConfig, Config>();
```

## Factory Method - Creational Pattern

When we don't know which class is needed at compile time, we use factory method.

### What's Factory Method?

This pattern's allowing you to create objects that has unique behaviours without specifying exact class. You define a common abstract class(need shared logic or fields) or interface(no shared code) for a family of related objects. Other classes should get implemented or extended by this base type with overriding methods. Main logic is creating and return the appropriate subclass. This pattern helps centralize object creation, flexibility and scalability.

#### Real World Example

You're creating a car tracking app. The app needs to track different types of cars like SUVs, Sedans and etc. each with unique behaviours (like SUV may need off-road tracking, while Sedan may focus on city routes). You define a common base (like a Car abstract class or ICar interface) and create subclasses for each vehicle type, but instead of creating those objects directly we use a factory class that can return the correct car type bases on some input like user selection or vehicle data. Factory Method will make your app flexible and open to future types like Electric Cars or Hybrids and more without changin the core logic.

## Builder - Creational Pattern

