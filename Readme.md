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
