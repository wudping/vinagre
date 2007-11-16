/*
 * vinagre-ui.h
 * This file is part of vinagre
 *
 * Copyright (C) 2007 - Jonh Wendell <wendell@bani.com.br>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __VINAGRE_UI_H__
#define __VINAGRE_UI_H__

#include <gtk/gtk.h>

#include "vinagre-commands.h"

G_BEGIN_DECLS

static const GtkActionEntry vinagre_always_sensitive_menu_entries[] =
{
  /* Toplevel */
  { "Machine", NULL, N_("_Machine") },
  { "Edit", NULL, N_("_Edit") },
  { "View", NULL, N_("_View") },
  { "Bookmarks", NULL, N_("_Bookmarks") },
  { "Help", NULL, N_("_Help") },

  /* Machine menu */
  { "MachineConnect", GTK_STOCK_CONNECT, NULL, "<control>N",
    N_("Connect into a remote machine"), G_CALLBACK (vinagre_cmd_machine_connect) },
  { "MachineOpen", GTK_STOCK_OPEN, NULL, "<control>O",
    N_("Open a .VNC file"), G_CALLBACK (vinagre_cmd_machine_open) },
  { "MachineQuit", GTK_STOCK_QUIT, NULL, "<control>Q",
    N_("Quit the program"), G_CALLBACK (gtk_main_quit) },
  	
  /* Bookmarks menu */
  { "BookmarksOpen", GTK_STOCK_CONNECT, N_("_Open bookmark"), NULL,
    N_("Connect into this machine"), G_CALLBACK (vinagre_cmd_bookmarks_open) },
  { "BookmarksEdit", GTK_STOCK_EDIT, N_("_Edit bookmark"), NULL,
    N_("Edit the details of selected bookmark"), G_CALLBACK (vinagre_cmd_bookmarks_edit) },
  { "BookmarksDel", GTK_STOCK_DELETE, N_("_Remove from bookmarks"), NULL,
    N_("Remove current selected connection from bookmarks"), G_CALLBACK (vinagre_cmd_bookmarks_del) },

  /* Help menu */
  {"HelpContents", GTK_STOCK_HELP, N_("_Contents"), "F1",
    N_("Open the vinagre manual"), NULL },
  { "HelpAbout", GTK_STOCK_ABOUT, NULL, NULL,
    N_("About this application"), G_CALLBACK (vinagre_cmd_help_about) }
};

static const GtkActionEntry vinagre_menu_entries[] =
{
  /* Machine menu */
  { "MachineClose", GTK_STOCK_CLOSE, NULL, "<control>W",
    N_("Close the current connection"), G_CALLBACK (vinagre_cmd_machine_close) },
  { "MachineCloseAll", GTK_STOCK_CLOSE, N_("C_lose All"), "<control><shift>W",
    N_("Close all active connections"), G_CALLBACK (vinagre_cmd_machine_close_all) },

  /* Bookmarks menu */
  { "BookmarksAdd", GTK_STOCK_SAVE, N_("_Add to bookmarks"), "<control>D",
    N_("Add current connection to your bookmarks"), G_CALLBACK (vinagre_cmd_bookmarks_add) }

};

static const GtkActionEntry vinagre_machine_connected_menu_entries[] =
{
  /* Machine menu */
  { "MachineTakeScreenshot", "applets-screenshooter", N_("Take screenshot"), NULL,
    N_("Take a screenshot of active connection"), G_CALLBACK (vinagre_cmd_machine_take_screenshot) },

  /* View menu */
  { "ViewFullScreen", GTK_STOCK_FULLSCREEN, NULL, "F11",
    N_("View the current machine in full screen"), G_CALLBACK (vinagre_cmd_view_fullscreen) },
};

static const GtkToggleActionEntry vinagre_always_sensitive_toggle_menu_entries[] =
{
  { "ViewToolbar", NULL, N_("_Toolbar"), NULL,
    N_("Show or hide the toolbar"),
    G_CALLBACK (vinagre_cmd_view_show_toolbar), FALSE },

  { "ViewStatusbar", NULL, N_("_Statusbar"), NULL,
    N_("Show or hide the statusbar"),
    G_CALLBACK (vinagre_cmd_view_show_statusbar), FALSE },

  { "ViewBookmarks", NULL, N_("_Bookmarks"), "F9",
    N_("Show or hide the bookmarks panel"),
    G_CALLBACK (vinagre_cmd_view_show_fav_panel), FALSE }
};

G_END_DECLS

#endif  /* __VINAGRE_UI_H__  */
/* vim: ts=8 */
