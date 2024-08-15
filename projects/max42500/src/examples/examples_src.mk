ifeq (y,$(strip $(APARD32690_MAX42500_APP)))
CFLAGS += -DAPARD32690_MAX42500_APP
SRCS += $(PROJECT)/src/examples/basic/max42500_app.c
INCS += $(PROJECT)/src/examples/basic/max42500_app.h
endif

ifeq (y,$(strip $(APARD32690_MAX42500_VIN_TEST)))
CFLAGS += -DAPARD32690_MAX42500_VIN_TEST
SRCS += $(PROJECT)/src/examples/voltage_monitor_testing/max42500_vin_test.c
INCS += $(PROJECT)/src/examples/voltage_monitor_testing/max42500_vin_test.h
endif

SRCS += $(PLATFORM_DRIVERS)/maxim_delay.c	\
	$(PLATFORM_DRIVERS)/maxim_irq.c		\
	$(PLATFORM_DRIVERS)/maxim_gpio.c	\
	$(PLATFORM_DRIVERS)/../common/maxim_dma.c		\
	$(PLATFORM_DRIVERS)/maxim_timer.c	\
	$(PLATFORM_DRIVERS)/maxim_init.c	\
	$(PLATFORM_DRIVERS)/maxim_uart.c	\
	$(PLATFORM_DRIVERS)/maxim_i2c.c\
	$(PLATFORM_DRIVERS)/maxim_uart_stdio.c
	
INCS += $(PLATFORM_DRIVERS)/maxim_irq.h		\
	$(PLATFORM_DRIVERS)/maxim_uart.h	\
	$(PLATFORM_DRIVERS)/maxim_timer.h	\
	$(PLATFORM_DRIVERS)/../common/maxim_dma.h	\
	$(PLATFORM_DRIVERS)/maxim_gpio.h	\
	$(PLATFORM_DRIVERS)/maxim_i2c.h\
	$(PLATFORM_DRIVERS)/maxim_uart_stdio.h