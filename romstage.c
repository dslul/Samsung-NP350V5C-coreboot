/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2008-2009 coresystems GmbH
 * Copyright (C) 2014 Vladimir Serbinenko
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of
 * the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/* FIXME: Check if all includes are needed. */

#include <stdint.h>
#include <string.h>
#include <timestamp.h>
#include <arch/byteorder.h>
#include <arch/io.h>
#include <device/mmio.h>
#include <device/pci_ops.h>
#include <device/pnp_ops.h>
#include <console/console.h>
#include <northbridge/intel/sandybridge/sandybridge.h>
#include <northbridge/intel/sandybridge/raminit_native.h>
#include <southbridge/intel/bd82x6x/pch.h>
#include <southbridge/intel/common/gpio.h>

void pch_enable_lpc(void)
{
	pci_write_config16(PCI_DEV(0, 0x1f, 0), 0x82, 0x3c00);
	pci_write_config32(PCI_DEV(0, 0x1f, 0), 0x84, 0x00040069);
	pci_write_config32(PCI_DEV(0, 0x1f, 0), 0x88, 0x0004fd61);
	pci_write_config32(PCI_DEV(0, 0x1f, 0), 0x8c, 0x00000000);
	pci_write_config32(PCI_DEV(0, 0x1f, 0), 0x90, 0x00000000);
	pci_write_config16(PCI_DEV(0, 0x1f, 0), 0x80, 0x0000);
}

void mainboard_rcba_config(void)
{
}

const struct southbridge_usb_port mainboard_usb_ports[] = {
	{ 1, 1, 0 },
	{ 1, 1, 0 },
	{ 1, 1, 1 },
	{ 1, 1, 1 },
	{ 0, 0, 2 },
	{ 0, 0, 2 },
	{ 0, 0, 3 },
	{ 0, 0, 3 },
	{ 1, 1, 4 },
	{ 1, 1, 4 },
	{ 0, 0, 5 },
	{ 1, 0, 5 },
	{ 0, 0, 6 },
	{ 0, 0, 6 },
};

void mainboard_early_init(int s3resume)
{
}

void mainboard_config_superio(void)
{
}

/* FIXME: Put proper SPD map here. */
void mainboard_get_spd(spd_raw_data *spd, bool id_only)
{
	read_spd(&spd[0], 0x50, id_only);
	read_spd(&spd[1], 0x51, id_only);
	read_spd(&spd[2], 0x52, id_only);
	read_spd(&spd[3], 0x53, id_only);
}
